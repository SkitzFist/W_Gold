#include "Collision.h"
#include <iostream>

void Collision::checkCollision()
{
	if (tiles->getIsWalkable()) {
		while (tiles->getSprite()->getGlobalBounds().intersects(gameObjects->getBounds())) {
			if (tiles->getSprite()->getGlobalBounds().left < gameObjects->getBounds().left) {
				if (rightSide(gameObjects, tiles)) {

				}
				else if (leftSide(gameObjects, tiles)) {

				}
				else if (topSide(gameObjects, tiles)) {

				}
				else if (botSide(gameObjects, tiles)) {

				}
			}
		}
	}
}

bool Collision::rightSide(GameObject* player, tile* tiles)
{
	return ;
}

bool Collision::leftSide(GameObject* player, tile* tiles)
{
	return false;
}

bool Collision::topSide(GameObject* player, tile* tiles)
{
	return false;
}

bool Collision::botSide(GameObject* player, tile* tiles)
{
	return false;
}

Collision::Collision()
{
	tiles = nullptr;
	gameObjects = nullptr;
}

void Collision::setUpCollision(GameObject* player, tile* tiles)
{
	gameObjects = player;
	this->tiles = tiles;
}

void Collision::update(Ray raycast[])
{
	//check collision
	checkCollision();
}
