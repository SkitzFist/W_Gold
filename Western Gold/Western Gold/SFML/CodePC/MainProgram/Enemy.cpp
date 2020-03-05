#include "Enemy.h"
#include "PatrollState.h"

//debug
#include <iostream>

Enemy::Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays, Grid* grid):
Entity(tex, rm, nrOfRays)
{
	//config

	//setup
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
	float speed = 100.f * static_cast<float>(delta.dt()); //Speed should be in entity
	if (currentState != nullptr) {
		currentState = currentState->update(delta);
	}
	moveSprite(dir, speed);
	
}

bool Enemy::shoot()
{
	return false;
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
	return false;
}

bool Enemy::seePlayer(bool col, DeltaTime dt)
{
	return false;
}
