#include "Enemy.h"
#include "PatrolState.h"

//debug
#include <iostream>

Enemy::Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays, Grid* grid):
Entity(tex, rm, nrOfRays)
{
	//config

	//setup
	
	//debug
	pathfinding = nullptr;
}

Enemy::~Enemy()
{
	//delete pathfinding;
}

void Enemy::update(DeltaTime delta)
{
	//if (isAtTile()) {
	//	if (pathfinding->getNextTile() != nullptr) {
	//		nextTile = pathfinding->getNextTile();
	//	}
	//}
	//if (nextTile != nullptr) {
	//	float speed = 10.f;
	//	moveSprite(getDir(), speed * delta.dt());
	//}
	
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

bool Enemy::isAtTile()
{
	bool isThere = false;
	if (nextTile == nullptr) {
		isThere = true;
	}
	else {
		if (getPosition() == static_cast<sf::Vector2f>(nextTile->getWorldPos())) {
			isThere = true;
		}
	}
	return isThere;
}
