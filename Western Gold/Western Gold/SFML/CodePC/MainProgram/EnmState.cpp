#include "EnmState.h"
#include "Enemy.h"
#include <iostream>

EnmState::EnmState(Enemy* enm)
{
	this->enm = enm;
	targetTile = nullptr;
	currentTile = nullptr;
	nextTile = nullptr;
}

EnmState::~EnmState()
{
	enm = nullptr;
}

Enemy* EnmState::getEnm() const
{
	return enm;
}

tile* EnmState::getTargetTile() const
{
	return targetTile;
}

void EnmState::setTargetTile(tile* tile)
{
	targetTile = tile;
}

tile* EnmState::getCurrentTile() const
{
	return currentTile;
}

void EnmState::setCurrentTile(tile* tile)
{
	currentTile = tile;
}

tile* EnmState::getNextTile() const
{
	return nextTile;
}

void EnmState::setNextTile(tile* tile)
{
	nextTile = tile;
}

void EnmState::setDirTowardsNextTile()
{
	sf::Vector2f dist = {
	static_cast<float>(nextTile->getWorldPos().x) - enm->getPosition().x,
	static_cast<float>(nextTile->getWorldPos().y) - getEnm()->getPosition().y
	};
	float magnitude = sqrt((dist.x * dist.x) + (dist.y * dist.y));
	sf::Vector2f dir = {
		dist.x / magnitude,
		dist.y / magnitude
	};
	getEnm()->setDir(dir);
}

bool EnmState::hasReachedTile(tile* t) const
{
	bool hasReached = false;

	float epsilon = 5.0;
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

void EnmState::calculatePath()
{
	if (getCurrentTile() != nullptr && getTargetTile() != nullptr) {
		getEnm()->getPathfinding()->findPath(currentTile->getWorldPos(), targetTile->getWorldPos());
	}
}
