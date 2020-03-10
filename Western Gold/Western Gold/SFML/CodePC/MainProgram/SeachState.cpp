#include <vector>
#include <random>

#include "SeachState.h"
#include "Enemy.h"
#include "AttackState.h"
#include "PatrollState.h"


//debug
#include <iostream>

SeachState::SeachState(Enemy* enemy, sf::Vector2f searchPos) :
	EnmState(enemy)
{
	//config
	maxSearchDistance = 10;
	maximumSearchTime = 30.f;
	minimumSearchTime = 10.f;
	//setup
	searchTime = randomFloat(minimumSearchTime, maximumSearchTime);
	searchTimer = 0.f;

	targetTile = enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(searchPos));
	currentTile = enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(enemy->getPosition()));
	nextTile = nullptr;

	calculatePath();
	//debug

	std::cout << "SearchTime: " << searchTime << std::endl;
}

EnmState* SeachState::update(DeltaTime time)
{
	EnmState* state = this;
	searchTimer += static_cast<float>(time.dt());

	move();
	if (getEnm()->getIsPlayerInSight()) {
		state = new AttackState(getEnm(), getEnm()->getPlayer());
		delete this;
	}

	if (searchTimer >= searchTime) {
		state = new PatrollState(getEnm(), getEnm()->getPatrollPoints(), getEnm()->getPatrollPointsLength());
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
	tile* current = targetTile;

	int numberOfTilesAway = randomInt(1, maxSearchDistance);

	while (numberOfTilesAway > 0)
	{
		std::vector<tile*> neighbours = getEnm()->getGrid()->getSurroundingTiles(current);
		int index = randomInt(0, (static_cast<int>(neighbours.size()) - 1));
		current = neighbours[index];
		neighbours.clear();
		--numberOfTilesAway;
	}

	return current;
}


int SeachState::randomInt(int min, int max) {
	int rv = NULL;

	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> dist(min, max);
	rv = dist(generator);
	return rv;
}

float SeachState::randomFloat(float min, float max) {
	float rv = NULL;
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> dist(min, max);
	rv = dist(generator);
	return rv;
}

