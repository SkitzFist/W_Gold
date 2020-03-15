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
	float speed = 50.f * static_cast<float>(delta.dt()); //TODO Speed should be in entity
	if (currentState != nullptr) {
		currentState = currentState->update(delta);
		moveSprite(dir, speed);
		float angle = 0;
		if (dir.x > 0.5) {
			angle = 90;
		}
		if (dir.x < -0.5) {
			angle = 270;
		}
		if (dir.y > 0.5) {
			angle = 180;
		}
		if (dir.y < -0.5) {
			angle = 0;
		}
		this->setRotatioSprite(angle);
		//this->rotateSprite(angle);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << "dir: " << dir.x << ", " << dir.y << std::endl;
		}

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