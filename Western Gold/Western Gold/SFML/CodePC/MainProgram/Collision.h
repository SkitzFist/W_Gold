#pragma once
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"
#include "GetDistance.h"

class Collision {
private:
	Player* player;
	//add a gameObject
	Enemy** enemies;
	tile** tiles;
	int nrOfTiles;
	int nrOfEnemies;

	void checkCollision();
	void checkCollisionRays(Ray raycast[], int nrOfRays = 0);
	//if gameobject is on the right side of tiles
	bool rightSide(GameObject*	gameObject, tile* tiles);
	bool leftSide(GameObject*	gameObject, tile* tiles);
	bool topSide(GameObject*	gameObject, tile* tiles);
	bool botSide(GameObject*	gameObject, tile* tiles);
	//from tile to player
	bool tileVisibility();
	//if player shoot/enemy shoot player
	
public:
	Collision();
	virtual ~Collision();
	bool enemySeeCollider();
	bool shootCollider(Entity* whatEntityShooting);
	void setUpCollision(Player* player, tile** tiles, Enemy** enemies, int nrOfTiles, int nrOfEnemies);
	void update();
};