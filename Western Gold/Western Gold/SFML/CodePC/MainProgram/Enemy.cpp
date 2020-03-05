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
	if (!(timeToNextShoot <= 0)) {
		timeToNextShoot -= delta.dt();
	}

	float speed = 50.f * static_cast<float>(delta.dt()); //Speed should be in entity
	if (currentState != nullptr) {
		currentState = currentState->update(delta);
	}
	Entity::update(delta);
	moveSprite(dir, speed);
	
}

bool Enemy::shoot()
{
	if (timeToNextShoot <= 0) {
		shooting = true;
		timeToNextShoot = timeBeetweenShoots;
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
	//std::cout << timeToNextShoot << std::endl;
	if (timeToNextShoot <= 0) {
		shooting = true;
		timeToNextShoot = timeBeetweenShoots;
		this->sound.PlaySounds(getRm()->getGunShot());
	}
	else {
		shooting = false;
	}
	return shooting;
}

bool Enemy::seePlayer(bool col, DeltaTime dt)
{
	bool theReturn = false;
	if (col) {
		//enemy ses player
		timeToShootPlayerSee += dt.dt();
		if (timeToShootPlayerSee >= timeToSeePlayer) {
			theReturn = true;
		}
	}
	else {
		timeToShootPlayerSee = 0;
	}
	return theReturn;
}
