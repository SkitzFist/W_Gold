#include "AttackState.h"
#include "Enemy.h"


AttackState::AttackState(Enemy* enemy, Player* player):
	EnmState(enemy)
{
	//config
	shootDistance = 20.f; //prob needs a lot of tweaking
	timesBetweenShots = 1.5f; //prob needs a lot of tweaking
	playerMaxDistance = 15.f; //If player moves this distance away from tile, Calculate new path
	//setup
	targetTile = enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(player->getPosition()));
	nextTile = nullptr;
	currentTile = enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(enemy->getPosition()));
	this->player = player;
	shootingTimer = timesBetweenShots;

	calculatePath();
	//debug	
}

AttackState::~AttackState()
{
	currentTile = nullptr;
	nextTile = nullptr;
	targetTile = nullptr;
}

EnmState* AttackState::update(DeltaTime time)
{
	EnmState* state = this;
	shootingTimer -= static_cast<float>(time.dt());

	if (getEnm()->getIsPlayerInSight()) {
		
		float playerDistanceFromTile = 
			getDistance(static_cast<sf::Vector2f>(targetTile->getWorldPos()), player->getPosition());

		if (playerDistanceFromTile < playerMaxDistance) {
			calculatePath();
		}
		move(time);

		if (canShoot()) {
			//shoot();

			shootingTimer = timesBetweenShots;
		}

	}
	else {
		//state = new SearchState(getEnm(), targetTile); Send in target tile so the enemy will search around that tile
		//delete this
	}


	return state;
}

void AttackState::shoot()
{
	//TODO raycasting
}

bool AttackState::canShoot()
{
	bool rv = false;
	if (getDistance(getEnm()->getPosition(), player->getPosition()) < shootDistance
		&& getEnm()->getIsPlayerInSight()
		&& shootingTimer <= 0) {
		rv = true;
	}
	return rv;
}

float AttackState::getDistance(sf::Vector2f a, sf::Vector2f b)
{
	float xDist = (b.x - a.x);
	float yDist = (b.y - a.y);
	float dist = abs(sqrt((xDist * xDist) + (yDist * yDist)));
	return dist;
}

sf::Vector2f AttackState::getDir()
{
	float xDist = (player->getPosition().x - getEnm()->getPosition().x);
	float yDist = (player->getPosition().y - getEnm()->getPosition().y);
	float magnitude = abs(sqrt((xDist * xDist) + (yDist * yDist)));

	sf::Vector2f dir{
		xDist / magnitude,
		yDist / magnitude
	};

	return dir;
}

void AttackState::move(DeltaTime time)
{
	if (nextTile == nullptr) {
		sf::Vector2f dir;
		currentTile = getEnm()->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(getEnm()->getPosition()));
		if (nextTile == nullptr) {
			nextTile = getEnm()->getPathfinding()->getNextTile();
			dir = getDir();
			getEnm()->setDir(dir);
		}
		if ((getDistance(getEnm()->getPosition(), player->getPosition())) <= shootDistance) {
			dir = { 0.f,0.f };
			getEnm()->setDir(dir);
		}
		else if (hasReachedTile(nextTile)) {
			nextTile = getEnm()->getPathfinding()->getNextTile();
			dir = getDir();
			getEnm()->setDir(dir);
		}
	}
}

bool AttackState::hasReachedTile(tile* t)
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

void AttackState::calculatePath()
{
	if (currentTile != nullptr && targetTile != nullptr) {
		getEnm()->getPathfinding()->findPath(currentTile->getWorldPos(), targetTile->getWorldPos());
	}
}
