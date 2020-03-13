#pragma once
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"
#include "GetDistance.h"
#include "Gold.h"
#include "Bullet.h"
#include "InsideWindow.h"

class Collision {
private:
	Player* player;
	//add a gameObject
	Gold** gold;
	Enemy** enemies;
	Grid* grid;
	Bullet** bull;

	tile** notWalkableTiles;
	int nrOfGold;
	int nrOfTiles;
	int nrOfEnemies;
	int nrOfBullets;

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
	bool shootCollider(Entity* whatEntityShooting, bool eShoot = false);
	void setUpCollision(Player* player, Grid* grid = nullptr, Enemy** enemies = nullptr, Gold** gold = nullptr, Bullet** bull = nullptr, int nrOfEnemies = 0, int nrOfGold = 0, int nrofBullets = 0);
	void update();
};