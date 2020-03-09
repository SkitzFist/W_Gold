#include "AttackState.h"
#include "Enemy.h"


AttackState::AttackState(Enemy* enemy, Player* player):
	EnmState(enemy)
{
	//config
	shootDistance = 20.f; //prob needs a lot of tweaking
	timesBetweenShots = 1.5f; //prob needs a lot of tweaking
	//setup
	targetTile = nullptr;
	nextTile = nullptr;
	currentTile = enemy->getGrid()->getTileFromWorldPos(static_cast<sf::Vector2i>(enemy->getPosition()));
	this->player = player;
	shootingTimer = timesBetweenShots;

	//debug	
}

EnmState* AttackState::update(DeltaTime time)
{
	EnmState* state = this;
	shootingTimer -= static_cast<float>(time.dt());

	//move();
	
	if (canShoot()) {
		//shoot();

		shootingTimer = timesBetweenShots;
	}

	//changeState();

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
		&& getEnm()->isPlayerInSight()
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

}
