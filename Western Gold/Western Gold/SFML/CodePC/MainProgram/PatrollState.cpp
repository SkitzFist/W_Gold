#include "PatrollState.h"
#include "Enemy.h"
#include "AttackState.h"

//debug
#include <iostream>

PatrollState::PatrollState(Enemy* enm) :
	EnmState(enm)
{
	//config

	//setup
	setCurrentTile(enm->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(getEnm()->getPosition())));
	setNextTarget();
	//debug

}

PatrollState::~PatrollState()
{

}

EnmState* PatrollState::update(DeltaTime time)
{
	EnmState* state = this;

	move(time);

	if (getEnm()->getIsPlayerInSight()) {
		state = new AttackState(getEnm(), getEnm()->getPlayer());
		delete this;
	}

	return state;
}

void PatrollState::move(DeltaTime time)
{
	sf::Vector2f dir;
	setCurrentTile(getEnm()->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(getEnm()->getPosition())));

	if (getNextTile() == nullptr) {
		setNextTile(getEnm()->getPathfinding()->getNextTile());
		setDirTowardsNextTile();
	}

	else if (hasReachedTile(getTargetTile())) {
		dir = { 0.f,0.f };
		getEnm()->setDir(dir);
		setNextTarget();
	}
	else if (hasReachedTile(getNextTile())) {
		setNextTile(getEnm()->getPathfinding()->getNextTile());
		setDirTowardsNextTile();
	}
}

void PatrollState::setNextTarget()
{
	tile* nextTarget = getEnm()->getGrid()->getTileFromWorldPos(
		getEnm()->getPatroll()->getNextPoint()
	);
	setTargetTile(nextTarget);
	calculatePath();
}