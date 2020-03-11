#include "Enemy.h"
#include "PatrollState.h"
#include "Collision.h"

//debug
#include <iostream>

Enemy::Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays, Grid* grid, Player* player):
Entity(tex, rm, nrOfRays)
{
	//config

	//setup
	this->player = player;
	pathfinding = new Pathfinding(grid);
	currentState = nullptr;
	patrollPoints = nullptr;
	patrollPointsLength = 0;
	this->grid = grid;
	dir = { 0.f, 0.f };
	isPlayerInSight = false;
	//debug

}

Enemy::~Enemy()
{
	delete currentState;
	delete pathfinding;
}

void Enemy::update(DeltaTime delta)
{
	float speed = 100.f * static_cast<float>(delta.dt()); //TODO Speed should be in entity
	if (currentState != nullptr) {
		currentState = currentState->update(delta);
		Entity::update(delta);
		moveSprite(dir, speed);
	}
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

void Enemy::setIsPlayerInSight(Collision& col)
{
	if (col.shootCollider(this, false)) {
		isPlayerInSight = true;
	}
	else {
		false;
	}
}

bool Enemy::getIsPlayerInSight()
{
	return isPlayerInSight;
}

Player* Enemy::getPlayer()
{
	//TODO skicka in i konstruktorn
	return nullptr;
}

sf::Vector2i* Enemy::getPatrollPoints() const
{
	return patrollPoints;
}

size_t Enemy::getPatrollPointsLength() const
{
	return patrollPointsLength;
}

Player* Enemy::getPlayer() const
{
	return player;
}