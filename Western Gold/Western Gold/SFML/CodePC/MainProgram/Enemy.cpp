#include "Enemy.h"
#include "PatrollState.h"
#include "Collision.h"

//debug
#include <iostream>

Enemy::Enemy(ResourceManager* rm, int nrOfRays, Grid* grid, Player* player):
Entity(rm->getEnemy(), rm, nrOfRays)
{
	//config
	seeDistance = 300;
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

bool Enemy::isShooting()
{
	return false;
}

int Enemy::getSeeDistance() const
{
	return this->seeDistance;
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

PatrollPoints* Enemy::getPatroll()
{
	return patroll;
}


Player* Enemy::getPlayer() const
{
	return player;
}