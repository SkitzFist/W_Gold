#include "Enemy.h"
#include "PatrolState.h"

//debug
#include <iostream>

Enemy::Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays, Grid* grid):
Entity(tex, rm, nrOfRays)
{
	//config

	//setup
	this->grid = grid;
	//debug
	pathfinding = new Pathfinding(grid);
}

Enemy::~Enemy()
{
	delete pathfinding;
}

bool Enemy::shoot()
{
	return false;
}

void Enemy::update(DeltaTime delta)
{
	if (hasReachedTargetTile()) {
		if (pathfinding->getNextTile() != nullptr) {
			nextTile = pathfinding->getNextTile();
		}
	}
	if (nextTile != nullptr) {
		float speed = 100.f;
		moveSprite(getDir(), speed * delta.dt());
	}
	
}

Pathfinding* Enemy::getPathfinding() const
{
	return pathfinding;
}

sf::Vector2f Enemy::getDir()
{
	sf::Vector2f tilePos = static_cast<sf::Vector2f>(nextTile->getWorldPos());
	sf::Vector2f dir = {
		tilePos.x - getPosition().x,
		tilePos.y - getPosition().y
	};

	float magnitude = sqrt((dir.x * dir.x) + (dir.y + dir.y));
	dir.x = dir.x / magnitude;
	dir.y = dir.y / magnitude;

	return dir;
}

bool Enemy::hasReachedTargetTile()
{
	bool isThere = false;
	if (nextTile == nullptr) {
		isThere = true;
	}
	else {
		tile* currentTile = grid->getTileFromWorldPos(static_cast<sf::Vector2i>(getPosition()));
		
		if (currentTile == nextTile) {
			isThere = true;
		}
	}
	return isThere;
}
