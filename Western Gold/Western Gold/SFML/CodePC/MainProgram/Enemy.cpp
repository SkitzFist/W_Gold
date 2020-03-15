#include "Enemy.h"
#include "PatrollState.h"
#include "Collision.h"

//debug
#include <iostream>

Enemy::Enemy(ResourceManager* rm, int nrOfRays, Grid* grid, Player* player):
Entity(rm->getEnemy(), rm, nrOfRays)
{
	//config
	seeDistance = 500;
	//setup
	patroll = nullptr;
	this->player = player;
	pathfinding = new Pathfinding(grid);
	currentState = nullptr;
	this->grid = grid;
	dir = { 0.f, 0.f };
	isPlayerInSight = false;
	//debug

}

Enemy::~Enemy()
{
	delete patroll;
	delete pathfinding;
	delete currentState;
}

void Enemy::update(DeltaTime delta)
{
	float speed = 50.f * static_cast<float>(delta.dt()); //TODO Speed should be in entity
	if (currentState != nullptr) {
		currentState = currentState->update(delta);
		moveSprite(dir, speed);
	}
	Entity::update(delta);
}

bool Enemy::shoot()
{
	return false;
}

Pathfinding* Enemy::getPathfinding() const
{
	return pathfinding;
}

void Enemy::setPatrollPoints(PatrollPoints* patroll)
{
	this->patroll = patroll;
	currentState = new PatrollState(this);
}

Grid* Enemy::getGrid() const
{
	return grid;
}

void Enemy::setDir(sf::Vector2f dir)
{
	this->dir = dir;
}

sf::Vector2f Enemy::getDir() const
{
	return dir;
}

bool Enemy::isShooting()
{
	return false;
}

int Enemy::getSeeDistance() const
{
	return this->seeDistance;
}

void Enemy::changePlayerInSight(bool Sight)
{
	this->isPlayerInSight = Sight;
}

void Enemy::setCollision(Collision& collision)
{
	this->collision = &collision;
}

Collision* Enemy::getCollision()
{
	return collision;
}

bool Enemy::getIsPlayerInSight()
{
	return isPlayerInSight;
}

PatrollPoints* Enemy::getPatroll()
{
	return patroll;
}


Player* Enemy::getPlayer() const
{
	return player;
}