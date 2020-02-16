#include "Collision.h"
#include <iostream>

void Collision::checkCollision()
{
	if (tiles->getIsWalkable()) {
		while (tiles->getSprite()->getGlobalBounds().intersects(gameObjects->getBounds())) {
				if (rightSide(gameObjects, tiles)) {
					std::cout << "Right" << std::endl;
					gameObjects->moveSprite(1, 0);
				}
				else if (leftSide(gameObjects, tiles)) {
					std::cout << "Left" << std::endl;
					gameObjects->moveSprite(-1, 0);
				}
				else if (topSide(gameObjects, tiles)) {
					gameObjects->moveSprite(0, -1);
				}
				else if (botSide(gameObjects, tiles)) {
					gameObjects->moveSprite(0, 1);
				}
				else {
					//MessageBox(nullptr, L"Error With Collision", L"ERROR", MB_ICONWARNING | MB_OK);
				}
			
		}
	}
}

bool Collision::rightSide(GameObject* gameObject, tile* tiles)
{
	bool theReturn = false;
	sf::FloatRect cTile = tiles->getSprite()->getGlobalBounds();
	if (gameObject->getRight() > (cTile.left + cTile.width)) {
		if (gameObject->getTop() > cTile.top && gameObject->getBot() < (cTile.top + cTile.height)) {
			theReturn = true;
		}
		else if (gameObject->getTop() < cTile.top && gameObject->getBot() > (cTile.top + cTile.height)) {
			theReturn = true;
		}
		else if (gameObject->getTop() < cTile.top) {
			if (cTile.top - gameObject->getTop() < gameObject->getRight() - (cTile.left + cTile.width)) {
				theReturn = true;
			}
		}
		else {
			if (gameObject->getBot() - (cTile.top + cTile.height) < gameObject->getRight() - (cTile.left + cTile.width)) {
				theReturn = true;
			}
		}
	}
	return theReturn;
}

bool Collision::leftSide(GameObject* gameObject, tile* tiles)
{

	bool theReturn = false;
	sf::FloatRect cTile = tiles->getSprite()->getGlobalBounds();
	if (gameObject->getLeft() < cTile.left) {
		if (gameObject->getTop() > cTile.top && gameObject->getBot() < (cTile.top + cTile.height)){
			theReturn = true;
		}
		if(gameObject->getTop() < cTile.top && gameObject->getBot() > (cTile.top + cTile.height)){
			theReturn = true;
		}
		if (gameObject->getTop() < cTile.top && cTile.top - gameObject->getTop() < cTile.left - gameObject->getLeft()) {
				theReturn = true;
		}
		if (gameObject->getBot() - (cTile.top + cTile.height) < cTile.left - gameObject->getLeft()) {
				theReturn = true;
		}
			
	}
	return theReturn;
}

bool Collision::topSide(GameObject* gameObject, tile* tiles)
{
	return false;
}

bool Collision::botSide(GameObject* gameObject, tile* tiles)
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
