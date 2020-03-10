#include "Collision.h"
#include <iostream>
#include <math.h>

void Collision::checkCollision()
{
	//tiles
	for (int x = 0; x < grid->getGridSize().x; x++) {
		for (int y = 0; y < grid->getGridSize().y; y++) {
			if (grid->getTiles()[y][x].getIsWalkable()) {
				while (grid->getTiles()[y][x].getSprite()->getGlobalBounds().intersects(player->getBounds())) {
					if (rightSide(player, &grid->getTiles()[y][x])) {
						player->moveSprite(1, 0);
					}
					else if (leftSide(player, &grid->getTiles()[y][x])) {
						player->moveSprite(-1, 0);
					}
					else if (topSide(player, &grid->getTiles()[y][x])) {
						player->moveSprite(0, -1);
					}
					else if (botSide(player, &grid->getTiles()[y][x])) {
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

	//gold
	for (int i = 0; i < nrOfGold; i++) {
		if (!gold[i]->take() && gold[i]->getBounds().intersects(player->getBounds())) {
			if (rightSide(player, gold[i])) {
				gold[i]->take(true);
			}
			else if (leftSide(player, gold[i])) {
				gold[i]->take(true);
			}
			else if (topSide(player, gold[i])) {
				gold[i]->take(true);
			}
			else if (botSide(player, gold[i])) {
				gold[i]->take(true);
			}
			else {
				std::cout << "error" << std::endl;
				//debug
				//MessageBox(nullptr, L"Error With Collision", L"ERROR", MB_ICONWARNING | MB_OK);
			}

		}
	}
	
}
//nope

#pragma region someFunctions
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

bool Collision::rightSide(GameObject* gameObj1, GameObject* gameObj2)
{
	bool theReturn = false;
	//if it kinda on the right side
	if (gameObj1->getRight() > (gameObj2->getRight())) {
		//om gameobject är imellan
		if (gameObj1->getTop() > gameObj2->getTop() && gameObj1->getBot() < (gameObj2->getBot())) {
			theReturn = true;
		}
		//om gameobject är över båda
		else if (gameObj1->getTop() <= gameObj2->getTop() && gameObj1->getBot() >= (gameObj2->getBot())) {
			theReturn = true;
		}
		else if (gameObj1->getTop() < gameObj2->getTop()) {
			if (gameObj2->getTop() - gameObj1->getTop() <= gameObj1->getRight() - (gameObj2->getRight())) {
				theReturn = true;
			}
		}
		else {
			if (gameObj1->getBot() - (gameObj2->getBot()) <= gameObj1->getRight() - (gameObj2->getRight())) {
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

bool Collision::leftSide(GameObject* gameObj1, GameObject* gameObj2)
{
	bool theReturn = false;
	if (gameObj1->getLeft() < gameObj2->getLeft()) {
		if (gameObj1->getTop() > gameObj2->getTop() && gameObj1->getBot() < (gameObj2->getBot())) {
			theReturn = true;
		}
		else if (gameObj1->getTop() <= gameObj2->getTop() && gameObj1->getBot() >= (gameObj2->getBot())) {
			theReturn = true;
		}
		else if (gameObj1->getTop() < gameObj2->getTop()) {
			if (gameObj2->getTop() - gameObj1->getTop() <= gameObj2->getLeft() - gameObj1->getLeft()) {
				theReturn = true;
			}
		}
		else if (gameObj1->getBot() - (gameObj2->getBot()) <= gameObj2->getLeft() - gameObj1->getLeft()) {
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

bool Collision::topSide(GameObject* gameObj1, GameObject* gameObj2)
{
	bool theReturn = false;
	if (gameObj1->getTop() < (gameObj2->getTop())) {
		//om gameobject är imellan
		if (gameObj1->getLeft() > gameObj2->getLeft()&& gameObj1->getRight() < (gameObj2->getRight())) {
			theReturn = true;
		}
		//om gameobject är över båda
		else if (gameObj1->getLeft() <= gameObj2->getLeft() && gameObj1->getRight() >= (gameObj2->getRight())) {
			theReturn = true;
		}
		else if (gameObj1->getLeft() < gameObj2->getLeft()) {
			if (gameObj2->getLeft() - gameObj1->getLeft() <= (gameObj2->getTop()) - gameObj1->getTop()) {
				theReturn = true;
			}
		}
		else {
			if (gameObj1->getRight() - (gameObj2->getRight()) <= (gameObj2->getTop()) - gameObj1->getTop()) {
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

bool Collision::botSide(GameObject* gameObj1, GameObject* gameObj2)
{
	bool theReturn = false;
	if (gameObj1->getBot() > (gameObj2->getBot())) {
		//om gameobject är imellan
		if (gameObj1->getLeft() > gameObj2->getLeft()&& gameObj1->getRight() < (gameObj2->getRight())) {
			theReturn = true;
		}
		//om gameobject är över båda
		else if (gameObj1->getLeft() <= gameObj2->getLeft() && gameObj1->getRight() >= (gameObj2->getRight())) {
			theReturn = true;
		}
		else if (gameObj1->getLeft() < gameObj2->getLeft()) {
			if (gameObj2->getLeft() - gameObj1->getLeft() <= gameObj1->getBot() - (gameObj2->getBot())) {
				theReturn = true;
			}
		}
		else {
			if (gameObj1->getRight() - (gameObj2->getRight()) <= gameObj1->getBot() - (gameObj2->getBot())) {
				theReturn = true;
			}
		}
	}
	return theReturn;
}
#pragma endregion

bool Collision::tileVisibility() {
	//tiles
	bool theReturn = true;
	for (int x = 0; x < nrOfTiles; x++) {
		for (int i = 0; i < nrOfTiles; i++) {
			if (x != i) {
				//if (player->getTileRay(x)->rayHitTile(tiles[i])) {
				//	tiles[x]->setWannaDraw(false);
				//	theReturn = false;
				//}
			}
		}
	}
	//and enemies
	for (int e = 0; e < nrOfEnemies; e++) {
		if (!enemies[e]->isDead()) {
			for (int x = 0; x < grid->getGridSize().x; x++) {
				for (int y = 0; y < grid->getGridSize().y; y++) {
					if (player->getEnemyRay(e)->rayHitTile(&grid->getTiles()[y][x])) {
						enemies[e]->setWannaDraw(false);
						theReturn = false;
					}
				}
			}
		}
	}
	return theReturn;
}
//Shoot collider doesnt go trough walls
bool Collision::shootCollider(Entity* whatEntityShooting, bool eShoot)
{
	bool theReturn = false;
	
	Enemy* enemy = dynamic_cast<Enemy*>(whatEntityShooting);
	if (enemy != nullptr) 
	{
		bool over = false;
		bool neverHitTile = true;
		bool saw = false;
		if (!eShoot) {
			for (int i = 0; i < whatEntityShooting->getNrOfRays() && !saw; i++) {

				//see
				if (!player->isDead() && whatEntityShooting->getRays()[i]->rayHitGameObject(player))
				{
					for (int x = 0; x < grid->getGridSize().x && !over; x++)
					{
						for (int y = 0; y < grid->getGridSize().y; y++) {

							if (whatEntityShooting->getShootRay()->rayHitTile2(&grid->getTiles()[y][x]))
							{
								neverHitTile = false;
								if (getDistance(whatEntityShooting->getPosition().x, whatEntityShooting->getPosition().y, (float)grid->getTiles()[y][x].getWorldPos().x, (float)grid->getTiles()[y][x].getWorldPos().y) >=
									getDistance(whatEntityShooting->getPosition().x, whatEntityShooting->getPosition().y, player->getPosition().x, player->getPosition().y))
								{
									theReturn = true;
									saw = true;
								}
								else {
									over = true;
								}
							}
						}
					}
					if (neverHitTile) {
						theReturn = true;
						saw = true;
					}
				}
				//getDistance(player->getPosition().x, player->getPosition().y, (float)tiles[t]->getWorldPos().x, (float)tiles[t]->getWorldPos().y) >
				//getDistance(player->getPosition().x, player->getPosition().y, whatEntityShooting->getPosition().x, whatEntityShooting->getPosition().y))
			}
		}
		//shoot
		if (eShoot) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				std::cout << "stop" << std::endl;
			}
			if (!player->isDead() && whatEntityShooting->getShootRay()->rayHitGameObject(player)) {
				for (int x = 0; x < grid->getGridSize().x && !over; x++) {
					for (int y = 0; y < grid->getGridSize().y; y++) {
						if (whatEntityShooting->getShootRay()->rayHitTile2(&this->grid->getTiles()[y][x])) {
							neverHitTile = false;
							if (getDistance(player->getPosition().x, player->getPosition().y, (float)grid->getTiles()[y][x].getWorldPos().x, (float)grid->getTiles()[y][x].getWorldPos().y) >
								getDistance(player->getPosition().x, player->getPosition().y, whatEntityShooting->getPosition().x, whatEntityShooting->getPosition().y))
							{
								theReturn = true;
								saw = true;
								std::cout << "player take damage" << std::endl;
								player->takeDamage();
							}
							else {
								over = true;
							}
						}
					}
				}
				if (neverHitTile) {
					theReturn = true;
					player->takeDamage();
					saw = true;
				}
			}
		}
	}
	else if (dynamic_cast<Player*>(whatEntityShooting) != nullptr) 
	{
		bool neverHitTile = true;
		bool over = false;
		for (int i = 0; i < nrOfEnemies; i++) {
			if (!enemies[i]->isDead() && player->getShootRay()->rayHitGameObject(enemies[i])) {
				for (int x = 0; x < grid->getGridSize().x && !over; x++) {
					for (int y = 0; y < grid->getGridSize().y; y++) {
						if (player->getShootRay()->rayHitTile2(&this->grid->getTiles()[y][x])) {
							neverHitTile = false;
							if (getDistance(player->getPosition().x, player->getPosition().y, (float)grid->getTiles()[y][x].getWorldPos().x, (float)grid->getTiles()[y][x].getWorldPos().y) >
								getDistance(player->getPosition().x, player->getPosition().y, enemies[i]->getPosition().x, enemies[i]->getPosition().y))
							{
								enemies[i]->takeDamage();
								theReturn = true;
							}
							else {
								over = true;
							}
						}
					}
				}
				if (neverHitTile) {
					enemies[i]->takeDamage();
					theReturn = true;
				}
			}
		}
	}
	else {
		std::cout << "error" << std::endl;
	}
	

	return theReturn;
}

Collision::Collision()
{
	grid = nullptr;
	player = nullptr;
	enemies = nullptr;
	gold = nullptr;
	this->nrOfEnemies = 0;
	this->nrOfTiles = 0;
	this->nrOfGold = 0;
}

Collision::~Collision()
{

}

bool Collision::enemySeeCollider()
{
	bool theReturn = false;
	//i = enemies, r = enemy rays, t = tiles;
	//see first if enemys ray hit player, then see if there is a wall beetween
	for (int i = 0; i < nrOfEnemies; i++) {
		for (int r = 0; r < enemies[i]->getNrOfRays(); r++) {
			if (enemies[i]->getRays()[r]->rayHitGameObject(player)) {
				//check so enemies dont see to far?
				for (int x = 0; x < grid->getGridSize().x; x++) {
					for (int y = 0; y < grid->getGridSize().y; y++) {
						if (enemies[i]->getRays()[r]->rayHitTile2(&grid->getTiles()[y][x])) {
							theReturn = true;
						}
						else {
							theReturn = true;
						}
					}
				}
			}
		}
	}
	return theReturn;
}

void Collision::setUpCollision(Player* player, Grid * grid, Enemy** enemies, Gold** gold, int nrOfEnemies, int nrOfGold)
{
	this->player = player;
	this->grid = grid;
	this->enemies = enemies;
	this->gold = gold;
	this->nrOfEnemies = nrOfEnemies;
	this->nrOfGold = nrOfGold;
}

void Collision::update()
{
	//check collision
	checkCollision();
	tileVisibility();

}
