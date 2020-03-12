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
	setTargetTile(enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(player->getPosition())));
	setNextTile(nullptr);
	setCurrentTile(enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(enemy->getPosition())));
	this->player = player;
	shootingTimer = timesBetweenShots;

	calculatePath();
	//debug	
}

AttackState::~AttackState()
{
}

EnmState* AttackState::update(DeltaTime time)
{
	EnmState* state = this;
	shootingTimer -= static_cast<float>(time.dt());

	if (getEnm()->getIsPlayerInSight()) {
		
		float playerDistanceFromTile = 
			getDistance(static_cast<sf::Vector2f>(getTargetTile()->getWorldPos()), player->getPosition());

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


void AttackState::move(DeltaTime time)
{
	if (getNextTile() == nullptr) {
		sf::Vector2f dir;
		setCurrentTile(getEnm()->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(getEnm()->getPosition())));
		if (getNextTile() == nullptr) {
			setNextTile(getEnm()->getPathfinding()->getNextTile());
			setDirTowardsNextTile();
		}
		if ((getDistance(getEnm()->getPosition(), player->getPosition())) <= shootDistance) {
			dir = { 0.f,0.f };
			getEnm()->setDir(dir);
		}
		else if (hasReachedTile(getNextTile())) {
			setNextTile(getEnm()->getPathfinding()->getNextTile());
			setDirTowardsNextTile();
		}
	}
}
