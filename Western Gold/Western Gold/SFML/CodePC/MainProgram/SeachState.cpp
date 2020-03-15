#include <vector>
#include <random>

#include "SeachState.h"
#include "Enemy.h"
#include "AttackState.h"
#include "PatrollState.h"



SeachState::SeachState(Enemy* enemy, sf::Vector2f searchPos) :
	EnmState(enemy)
{
	//config
	maxSearchDistance = 10;
	maximumSearchTime = 20.f;
	minimumSearchTime = 5.f;

	//setup
	searchTime = randomFloat(minimumSearchTime, maximumSearchTime);
	searchTimer = 0.f;

	setTargetTile(enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(searchPos)));
	setCurrentTile(enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(enemy->getPosition())));
	setNextTile(nullptr);
	calculatePath();
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
	else if (searchTimer >= searchTime) {
		state = new PatrollState(getEnm());
		delete this;
	}
	return state;
}

void SeachState::move()
{
	sf::Vector2f dir;
	setCurrentTile(getEnm()->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(getEnm()->getPosition())));
	if (getNextTile() == nullptr) {
		setNextTile(getEnm()->getPathfinding()->getNextTile());
		setDirTowardsNextTile();
	}
	if (hasReachedTile(getTargetTile())) {
		dir = { 0.f,0.f };
		getEnm()->setDir(dir);
		setNextTarget();
		getEnm()->getPathfinding()->findPath(getCurrentTile(), getTargetTile());
	}
	else if (hasReachedTile(getNextTile())) {
		setNextTile(getEnm()->getPathfinding()->getNextTile());
		setDirTowardsNextTile();;
	}
	rotate();
}

void SeachState::setNextTarget()
{
	tile* current = getTargetTile();

	int numberOfTilesAway = randomInt(1, maxSearchDistance);

	while (numberOfTilesAway > 0)
	{
		std::vector<tile*> neighbours = getEnm()->getGrid()->getSurroundingTiles(current);
		int index = randomInt(0, (static_cast<int>(neighbours.size()) - 1));
		current = neighbours[index];
		neighbours.clear();
		--numberOfTilesAway;
	}

	setTargetTile(current);
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

