#include "SeachState.h"
#include "Enemy.h"
#include "AttackState.h"
#include "PatrollState.h"

SeachState::SeachState(Enemy* enemy, sf::Vector2f searchPos) :
	EnmState(enemy)
{
	//config

	//setup
	targetTile = enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(searchPos));
	currentTile = enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(enemy->getPosition()));
	nextTile = nullptr;
	calculatePath();
	//debug
}

EnmState* SeachState::update(DeltaTime time)
{
	EnmState* state = this;

	move();

	if (getEnm()->getIsPlayerInSight()) {
		state = new AttackState(getEnm(), getEnm()->getPlayer());
		delete this;
	}

	return state;
}

void SeachState::move()
{
	sf::Vector2f dir;
	currentTile = getEnm()->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(getEnm()->getPosition()));
	if (nextTile == nullptr) {
		nextTile = getEnm()->getPathfinding()->getNextTile();
		dir = getDir();
		getEnm()->setDir(dir);
	}
	if (hasReachedTile(targetTile)) {
		dir = { 0.f,0.f };
		getEnm()->setDir(dir);
		getEnm()->getPathfinding()->clearPath();
		targetTile = getNextTarget();
		getEnm()->getPathfinding()->findPath(currentTile, targetTile);
	}
	else if (hasReachedTile(nextTile)) {
		nextTile = getEnm()->getPathfinding()->getNextTile();
		dir = getDir();
		getEnm()->setDir(dir);
	}
}

void SeachState::calculatePath()
{
	if (currentTile != nullptr && targetTile != nullptr) {
		getEnm()->getPathfinding()->findPath(currentTile, targetTile);
	}
}

sf::Vector2f SeachState::getDir()
{
	sf::Vector2f dist = {
		static_cast<float>(nextTile->getWorldPos().x) - getEnm()->getPosition().x,
		static_cast<float>(nextTile->getWorldPos().y) - getEnm()->getPosition().y
	};
	float magnitude = sqrt((dist.x * dist.x) + (dist.y * dist.y));
	sf::Vector2f dir = {
		dist.x / magnitude,
		dist.y / magnitude
	};
	return dir;
}

bool SeachState::hasReachedTile(tile* t)
{
	bool hasReached = false;

	long double epsilon = 5.0;

	sf::Vector2f dist = {
		static_cast<float>(t->getWorldPos().x) - getEnm()->getPosition().x,
		static_cast<float>(t->getWorldPos().y) - getEnm()->getPosition().y
	};
	long double length = sqrt((dist.x * dist.x) + (dist.y * dist.y));

	if (length <= epsilon) {
		hasReached = true;
	}

	return hasReached;
}

tile* SeachState::getNextTarget()
{
	tile* t = nullptr;
	return nullptr;
}
