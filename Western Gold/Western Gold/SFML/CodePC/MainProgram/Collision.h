#pragma once
#include "Tile.h"
#include "Player.h"
#include "EnemyHandler.h"
#include "GetDistance.h"
#include "Gold.h"
#include "Bullet.h"
#include "InsideWindow.h"

class Collision {
private:
	Player* player;
	//add a gameObject
	Gold** gold;
	Grid* grid;
	Bullet** bull;

	tile** notWalkableTiles;
	int nrOfGold;
	int nrOfTiles;
	int nrOfBullets;

	int nrOfEnemies;
	Enemy** enemies;
	EnemyHandler* enemyHandler;


	ResourceManager* rm;
	void checkCollision();
	//if gameobject is on the right side of tiles
	bool rightSide(GameObject*	gameObject, tile* tiles);
	bool rightSide(GameObject*  gameObj1, GameObject* gameObj2);
	bool leftSide(GameObject*	gameObject, tile* tiles);
	bool leftSide(GameObject* gameObj1, GameObject* gameObj2);
	bool topSide(GameObject*	gameObject, tile* tiles);
	bool topSide(GameObject* gameObj1, GameObject* gameObj2);
	bool botSide(GameObject*	gameObject, tile* tiles);
	bool botSide(GameObject* gameObj1, GameObject* gameObj2);
	//from tile to player
	bool tileVisibility();
	//if player shoot/enemy shoot player
	
public:
	Collision(ResourceManager* rm);
	virtual ~Collision();
	bool enemySeeCollider(Enemy* enemy);
	bool outSide();
	bool shootCollider(Entity* whatEntityShooting, bool eShoot = false);
	void setUpCollision(Player* player, Grid* grid = nullptr, EnemyHandler *enemyHandler = nullptr, Gold** gold = nullptr, Bullet** bull = nullptr, int nrOfGold = 0, int nrofBullets = 0);
	void update();
};