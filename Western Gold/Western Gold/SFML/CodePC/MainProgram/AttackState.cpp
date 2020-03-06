#include "AttackState.h"
#include "Enemy.h"


AttackState::AttackState(Enemy* enemy, Player* player):
	EnmState(enemy)
{
	//config
	shootDistance = 20.f; //prob needs a lot of tweaking
	timesBetweenShots = 1.5f; //prob needs a lot of tweaking
	//setup
	this->player = player;
	shootingTimer = timesBetweenShots;

	//debug	
}

EnmState* AttackState::update(DeltaTime time)
{
	EnmState* state = this;
	shootingTimer -= static_cast<float>(time.dt);

	//move();
	
	if (canShoot()) {
		//shoot();
		
	}

	//changeState();

	return state;
}

void AttackState::shoot()
{
	//Bullet* bullet = new Bullet(dir?);
}

bool AttackState::canShoot()
{
	bool rv = false;
	if (getDistance() < shootDistance
		&& getEnm()->isPlayerInSight
		&& shootingTimer <= 0) {
		rv = true;
		shootingTimer = timesBetweenShots;
	}
	return rv;
}

float AttackState::getDistance()
{
	float xDist = (player->getPosition().x - getEnm()->getPosition().x);
	float yDist = (player->getPosition().y - getEnm()->getPosition().y);
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
