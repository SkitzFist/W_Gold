#include "Enemy.h"
#include "PatrollState.h"

//debug
#include <iostream>

Enemy::Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays, Grid* grid):
Entity(tex, rm, nrOfRays)
{
	//config

	//setup
	shooting = false;
	this->timeToSeePlayer = 0.5f;
	this->timeBeetweenShoots = 1.5f;
	this->timeToNextShoot = 0.f;
	this->timeToShootPlayerSee = 0.f;
	this->rotationSpeed = 100.0f;

	pathfinding = new Pathfinding(grid);
	currentState = nullptr;
	patrollPoints = nullptr;
	patrollPointsLength = 0;
	this->grid = grid;
	dir = { 0.f, 0.f };
	//debug

}

Enemy::~Enemy()
{
	delete currentState;
	delete pathfinding;
}

void Enemy::update(DeltaTime delta)
{
	if (!isDead()) {
		if (!(timeToNextShoot <= 0)) {
			timeToNextShoot -= (float)delta.dt();
		}
		float speed = 100.f * static_cast<float>(delta.dt()); //Speed should be in entity
		if (currentState != nullptr) {
			currentState = currentState->update(delta);
		}
		Entity::update(delta);
		moveSprite(dir, speed);
	}
}

bool Enemy::shoot()
{
	if (!isDead()) {
		if (timeToNextShoot <= 0) {
			shooting = true;
			timeToNextShoot = timeBeetweenShoots;
			//must create a line from enemy and out(ass a shot)
		}
		else {
			shooting = false;
		}
	}
	return shooting;
}

Pathfinding* Enemy::getPathfinding() const
{
	return pathfinding;
}

void Enemy::engagePatrolState(sf::Vector2i points[], size_t length)
{
	patrollPointsLength = length;
	patrollPoints = points;

	currentState = new PatrollState(this, patrollPoints, patrollPointsLength);
}

Grid* Enemy::getGrid() const
{
	return grid;
}

void Enemy::setDir(sf::Vector2f dir)
{
	this->dir = dir;
}

bool Enemy::isShooting()
{
	if (!isDead()) {
		if (timeToNextShoot <= 0) {
			this->shooting = true;
			timeToNextShoot = timeBeetweenShoots;
			this->sound.PlaySounds(getRm()->getGunShot());
		}
		else {
			this->shooting = false;
		}
	}
	else {
		shooting = false;
	}
	return shooting;
}

bool Enemy::seePlayer(bool col, DeltaTime dt)
{
	bool theReturn = false;
	if (!isDead()) {
		if (col) {
			//enemy ses player
			timeToShootPlayerSee += (float)dt.dt();
			if (timeToShootPlayerSee >= timeToSeePlayer) {
				theReturn = true;
			}
		}
		else {
			timeToShootPlayerSee = 0;
		}
	}
	else {
		theReturn = false;
	}
	return theReturn;
}

void Enemy::rotateTowards(GameObject* gameObj, DeltaTime dt)
{
	sf::Vector2f bc = this->getPosition() - gameObj->getPosition();
	float v = atan2f(bc.x, bc.y);
	v = (((float)((int)(((v * 180.0f) / 3.14f + 180.0f + this->getRotation()) * 10)%3600)) / 10);
	if (v > 180) {
		this->addRotationSprite(-rotationSpeed * (float)dt.dt());
	}
	else {
		this->addRotationSprite(rotationSpeed * (float)dt.dt());
	}

}
