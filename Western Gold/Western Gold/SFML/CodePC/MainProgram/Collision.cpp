#include "Collision.h"
#include <iostream>
#include <math.h>

void Collision::checkCollision()
{
	for (int i = 0; i < nrOfTiles; i++) {
		if (tiles[i]->getIsWalkable()) {
			while (tiles[i]->getSprite()->getGlobalBounds().intersects(player->getBounds())) {
				if (rightSide(player, tiles[i])) {
					player->moveSprite(1, 0);
				}
				else if (leftSide(player, tiles[i])) {
					player->moveSprite(-1, 0);
				}
				else if (topSide(player, tiles[i])) {
					player->moveSprite(0, -1);
				}
				else if (botSide(player, tiles[i])) {
					player->moveSprite(0, 1);
				}
				else {
					std::cout << "error" << std::endl;
					//debug
					//MessageBox(nullptr, L"Error With Collision", L"ERROR", MB_ICONWARNING | MB_OK);
				}

			}
		}
	}
}

void Collision::checkCollisionRays(Ray raycast[], int nrOfRays)
{
	for (int r = 0; r < nrOfRays; r++) {
		for (int t = 0; t < nrOfTiles; t++) {
			
		}
	}
}

bool Collision::rightSide(GameObject* gameObject, tile* tiles)
{
	bool theReturn = false;
	sf::FloatRect cTile = tiles->getSprite()->getGlobalBounds();
	//if it kinda on the right side
	if (gameObject->getRight() > (cTile.left + cTile.width)) {
		//om gameobject är imellan
		if (gameObject->getTop() > cTile.top && gameObject->getBot() < (cTile.top + cTile.height)) {
			theReturn = true;
		}
		//om gameobject är över båda
		else if (gameObject->getTop() <= cTile.top && gameObject->getBot() >= (cTile.top + cTile.height)) {
			theReturn = true;
		}
		else if (gameObject->getTop() < cTile.top) {
			if (cTile.top - gameObject->getTop() <= gameObject->getRight() - (cTile.left + cTile.width)) {
				theReturn = true;
			}
		}
		else {
			if (gameObject->getBot() - (cTile.top + cTile.height) <= gameObject->getRight() - (cTile.left + cTile.width)) {
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
		else if(gameObject->getTop() <= cTile.top && gameObject->getBot() >= (cTile.top + cTile.height)){
			theReturn = true;
		}
		else if (gameObject->getTop() < cTile.top){
			if (cTile.top - gameObject->getTop() <= cTile.left - gameObject->getLeft()) {
				theReturn = true;
			}
		}
		else if (gameObject->getBot() - (cTile.top + cTile.height) <= cTile.left - gameObject->getLeft()) {
				theReturn = true;
		}
			
	}
	return theReturn;
}

bool Collision::topSide(GameObject* gameObject, tile* tiles)
{
	bool theReturn = false;
	sf::FloatRect cTile = tiles->getSprite()->getGlobalBounds();
	if (gameObject->getTop() < (cTile.top)) {
		//om gameobject är imellan
		if (gameObject->getLeft() > cTile.left && gameObject->getRight() < (cTile.left + cTile.width)) {
			theReturn = true;
		}
		//om gameobject är över båda
		else if (gameObject->getLeft() <= cTile.left && gameObject->getRight() >= (cTile.left + cTile.width)) {
			theReturn = true;
		}
		else if (gameObject->getLeft() < cTile.left) {
			if (cTile.left - gameObject->getLeft() <= (cTile.top) - gameObject->getTop()) {
				theReturn = true;
			}
		}
		else {
			if (gameObject->getRight() - (cTile.left + cTile.width) <= (cTile.top) - gameObject->getTop()) {
				theReturn = true;
			}
		}
	}
	return theReturn;
}

bool Collision::botSide(GameObject* gameObject, tile* tiles)
{
	bool theReturn = false;
	sf::FloatRect cTile = tiles->getSprite()->getGlobalBounds();
	if (gameObject->getBot() > (cTile.top + cTile.height)) {
		//om gameobject är imellan
		if (gameObject->getLeft() > cTile.left && gameObject->getRight() < (cTile.left + cTile.width)) {
			theReturn = true;
		}
		//om gameobject är över båda
		else if (gameObject->getLeft() <= cTile.left && gameObject->getRight() >= (cTile.left + cTile.width)) {
			theReturn = true;
		}
		else if (gameObject->getLeft() < cTile.left) {
			if (cTile.left - gameObject->getLeft() <= gameObject->getBot() - (cTile.top + cTile.height)) {
				theReturn = true;
			}
		}
		else {
			if (gameObject->getRight() - (cTile.left + cTile.width) <= gameObject->getBot() - (cTile.top + cTile.height)) {
				theReturn = true;
			}
		}
	}
	return theReturn;
}

/*bool Collision::tileVisibility()
{
	for (int x = 0; x < nrOfTiles; x++) {
		for (int y = 0; y < nrOfTiles; y++) {
			if (x != y) {
				
				//must check who is the nerest
				if (tiles[x]->getRay()->rayHitTile(tiles[y])) {
					float xToP = getDistance(
						(float)tiles[x]->getWorldPos().x, (float)tiles[x]->getWorldPos().y,
						gameObjects->getPosition().x, gameObjects->getPosition().y
					);
					float yToP = getDistance(
						(float)tiles[y]->getWorldPos().x, (float)tiles[y]->getWorldPos().y,
						gameObjects->getPosition().x, gameObjects->getPosition().y
					);
					float XToY = getDistance(
						(float)tiles[y]->getWorldPos().x, (float)tiles[y]->getWorldPos().y,
						(float)tiles[x]->getWorldPos().x, (float)tiles[x]->getWorldPos().y
						);
					//jag e närmare spelaren
					if (xToP > yToP) {
						//jag nuddade spelaren först
						if (XToY < xToP) {
							tiles[x]->setWannaDraw(false);
						}
						
					}
					
				}
			}
		}
	}
	


	return false;
}
*/
bool Collision::tileVisibility() {
	for (int x = 0; x < nrOfTiles; x++) {
		for (int i = 0; i < nrOfTiles; i++) {
			if (x != i) {
				if (player->getRay(x)->rayHitTile(tiles[i])) {
					if (getDistance(player->getPosition().x, player->getPosition().y, (float)tiles[i]->getSprite()->getPosition().x, (float)tiles[i]->getSprite()->getPosition().x)
						<
						getDistance(player->getPosition().x, player->getPosition().y, (float)tiles[x]->getSprite()->getPosition().x, (float)tiles[x]->getSprite()->getPosition().x)) 
					{
						tiles[x]->setWannaDraw(false);
					}
				}
			}
		}
	}
	
	//for (int x = 0; x < 2; x++) {
	//	for (int i = 0; i < 2; i++) {
	//		if (x != i) {
	//			if (player->getRay(x)->rayHitTile(tiles[i])) {
	//				if (getDistance(
	//					(float)tiles[x]->getWorldPos().x, (float)tiles[x]->getWorldPos().y,
	//					player->getPosition().x, player->getPosition().y
	//				)
	//				>
	//					getDistance(
	//					(float)tiles[i]->getWorldPos().x, (float)tiles[i]->getWorldPos().y,
	//						player->getPosition().x, player->getPosition().y
	//					)) {
	//					tiles[x]->setWannaDraw(false);
	//				}
	//			}
	//		}
	//	}
	//}
	return false;
}

bool Collision::shootCollider(Entity* player, Entity* enemies)
{
	return player->getRays()->rayHitGameObject(enemies);;
}



Collision::Collision()
{
	tiles = nullptr;
	player = nullptr;
	this->nrOfTiles = 0;
}

Collision::~Collision()
{

	//delete this->player;
	//delete this->tiles;
}

void Collision::setUpCollision(Player* player, tile** tiles, int nrOfTiles)
{
	this->player = player;
	this->tiles = tiles;
	this->nrOfTiles = nrOfTiles;
}

void Collision::update(Ray raycast[], int nrOfRays)
{
	//check collision
	checkCollision();
	tileVisibility();
	//if (raycast != nullptr) {
	//	checkCollisionRays(raycast, nrOfRays);
	//}
}
