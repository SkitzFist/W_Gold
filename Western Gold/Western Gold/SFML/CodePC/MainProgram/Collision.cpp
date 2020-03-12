#include "Collision.h"
#include <iostream>
#include <math.h>

void Collision::checkCollision()
{
	//tiles
	for (int x = 0; x < grid->getGridSize().x; x++) {
		for (int y = 0; y < grid->getGridSize().y; y++) {
			if (!grid->getTiles()[y][x].getIsWalkable()) {
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
		//om gameobject �r imellan
		if (gameObject->getTop() > cTile.top && gameObject->getBot() < (cTile.top + cTile.height)) {
			theReturn = true;
		}
		//om gameobject �r �ver b�da
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
		//om gameobject �r imellan
		if (gameObj1->getTop() > gameObj2->getTop() && gameObj1->getBot() < (gameObj2->getBot())) {
			theReturn = true;
		}
		//om gameobject �r �ver b�da
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
		//om gameobject �r imellan
		if (gameObject->getLeft() > cTile.left && gameObject->getRight() < (cTile.left + cTile.width)) {
			theReturn = true;
		}
		//om gameobject �r �ver b�da
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
		//om gameobject �r imellan
		if (gameObj1->getLeft() > gameObj2->getLeft()&& gameObj1->getRight() < (gameObj2->getRight())) {
			theReturn = true;
		}
		//om gameobject �r �ver b�da
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
		//om gameobject �r imellan
		if (gameObject->getLeft() > cTile.left && gameObject->getRight() < (cTile.left + cTile.width)) {
			theReturn = true;
		}
		//om gameobject �r �ver b�da
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
		//om gameobject �r imellan
		if (gameObj1->getLeft() > gameObj2->getLeft()&& gameObj1->getRight() < (gameObj2->getRight())) {
			theReturn = true;
		}
		//om gameobject �r �ver b�da
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

	//gold
	for (int g = 0; g < nrOfGold; g++) {
		bool seeGold = true;
		for (int i = 0; i < grid->getNrOfNotWalkableTiles() && seeGold; i++)
		{
			//ass
			
			if (player->getGoldRay(g)->rayHitTile(notWalkableTiles[i]))
			{
				gold[g]->setWannaDraw(false);
				theReturn = false;
				seeGold = false;
			}
		}
	}
	//and enemies
	for (int e = 0; e < nrOfEnemies; e++) 
	{
		if (!enemies[e]->isDead()) 
		{
			bool seeEnemy = true;
			for (int i = 0; i < grid->getNrOfNotWalkableTiles() && seeEnemy ; i++)
			{
				if (insideWindow(notWalkableTiles[i], rm->getView())) {
					if (player->getEnemyRay(e)->rayHitTile(notWalkableTiles[i]))
					{
						enemies[e]->setWannaDraw(false);
						theReturn = false;
						seeEnemy = true;
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
		//shoot
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
	else if (dynamic_cast<Player*>(whatEntityShooting) != nullptr) 
	{
		bool neverHitTile = true;
		bool over = false;
		for (int i = 0; i < nrOfEnemies; i++) {
			if (insideWindow(enemies[i], rm->getView())) {
				if (!enemies[i]->isDead() && player->getShootRay()->rayHitGameObject(enemies[i])) {
					for (int x = 0; x < (float)grid->getGridSize().x && !over; x++) {
						for (int y = 0; y < (float)grid->getGridSize().y; y++) {
							if (player->getShootRay()->rayHitTile2(&this->grid->getTiles()[y][x])) {
								neverHitTile = false;
								if (getDistance(player->getPosition().x, player->getPosition().y, (float)grid->getTiles()[y][x].getWorldPos().x, (float)grid->getTiles()[y][x].getWorldPos().y) >
									getDistance(player->getPosition().x, player->getPosition().y, enemies[i]->getPosition().x, enemies[i]->getPosition().y))
								{
									enemies[i]->takeDamage();
									theReturn = true;
								}
								else {
									//over = true;
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
	}
	else {
		std::cout << "error" << std::endl;
	}
	

	return theReturn;
}

Collision::Collision(ResourceManager* rm)
{
	this->rm = rm;
	grid = nullptr;
	player = nullptr;
	enemies = nullptr;
	gold = nullptr;
	this->notWalkableTiles = nullptr;
	this->nrOfEnemies = 0;
	this->nrOfTiles = 0;
	this->nrOfGold = 0;
}

Collision::~Collision()
{
	delete[] notWalkableTiles;
}


bool Collision::enemySeeCollider(Enemy* enemy)
{
	bool theReturn = false;
	int howFastLook = 2;
	if (insideWindow(enemy, rm->getView())) {
		for (int i = 0; i < enemy->getNrOfRays(); i++) {
			float distance = getDistance(player, enemy);
				float maxDistance = enemy->getSeeDistance();
				float k = (float)((enemy->getRays()[i]->returnThisLine().getLineY1() - enemy->getRays()[i]->returnThisLine().getLineY2()) / (enemy->getRays()[i]->returnThisLine().getLineX1() - enemy->getRays()[i]->returnThisLine().getLineX2()));
				float m = (float)(enemy->getRays()[i]->returnThisLine().getLineY1() - (k * enemy->getRays()[i]->returnThisLine().getLineX1()));
				int p = 1;
				int rayRoation = ((int)enemy->getRays()[i]->getRotation() % 360);
				bool foundWall = false;
				for (int see = 0; see < maxDistance && !foundWall; see += howFastLook)
				{
					int y = sin((rayRoation * (3.14f / 180.f) - 1.57f)) * see + enemy->getPosition().y;
					int x = cos((rayRoation * (3.14f / 180.f) - 1.57f)) * see + enemy->getPosition().x;
					tile* seetile = nullptr;
					seetile = grid->getTileFromWorldPos(sf::Vector2i(x, y));
					if (x > player->getBounds().left&& x < player->getBounds().left + player->getBounds().width &&
						y > player->getBounds().top&& y < player->getBounds().top + player->getBounds().height)
					{
						theReturn = true;
					}
					if (seetile != nullptr) {
						//see things
						if (!seetile->getIsWalkable()) {
							foundWall = true;
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
	int i = 0;
	notWalkableTiles = new tile*[grid->getNrOfNotWalkableTiles()];
	for (int y = 0; y < grid->getGridSize().y; y++) {
		for (int x = 0; x < grid->getGridSize().x; x++) {
			if (!grid->getTiles()[y][x].getIsWalkable()) 
			{
				notWalkableTiles[i] = &grid->getTiles()[y][x];
				i++;
			}
		}
	}
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
	//grid->getTileFromWorldPos(sf::Vector2i(60, 60))->setWannaDraw(false);
}
