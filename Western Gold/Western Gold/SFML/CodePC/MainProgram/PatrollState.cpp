#include "PatrollState.h"
#include "Enemy.h"
#include "AttackState.h"

//debug
#include <iostream>

PatrollState::PatrollState(Enemy* enm, sf::Vector2i* patrollPoints, size_t patrollPointsLength) :
	EnmState(enm)
{
	//config

	//setup
	currentIndex = 0;
	nextTile = nullptr;
	targetTile = nullptr;
	currentTile = enm->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(getEnm()->getPosition()));
	patrollTilesLength = patrollPointsLength;
	setupPatrollTiles(patrollPoints);

	//debug

}

PatrollState::~PatrollState()
{
	delete[] patrollTiles;
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
	if (hasReachedTile(nextTile)) {
		nextTile = getEnm()->getPathfinding()->getNextTile();
		dir = getDir();
		getEnm()->setDir(dir);
	}
}

void PatrollState::setupPatrollTiles(sf::Vector2i* patrollPoints)
{
	patrollTiles = new tile*[patrollTilesLength];
	for (size_t i = 0; i < patrollTilesLength; ++i) {
		patrollTiles[i] = getEnm()->getGrid()->getTileFromWorldPos(patrollPoints[i]);
	}

	//debug:
	currentIndex = 1;
	targetTile = patrollTiles[1];
	calculatePath();
}

void PatrollState::calculatePath()
{
	if (currentTile != nullptr && targetTile != nullptr) {
		getEnm()->getPathfinding()->findPath(currentTile->getWorldPos(), targetTile->getWorldPos());
	}
}

bool PatrollState::hasReachedTile(tile* t)
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

sf::Vector2f PatrollState::getDir()
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

tile* PatrollState::getNextTarget()
{
	currentIndex = (currentIndex + 1) % static_cast<int>(patrollTilesLength);
	tile* nextTarget = patrollTiles[currentIndex];
	return nextTarget;
}