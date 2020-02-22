#pragma once
#include "Tile.h"
#include "Player.h"
//#include "Gold"
#include "GetDistance.h"

class Collision {
private:
	Player* player;
	//add a gameObject
	tile** tiles;
	int nrOfTiles;
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
	bool shootCollider(Entity *player, Entity* enemies);
public:
	Collision();
	virtual ~Collision();
	void setUpCollision(Player* player, tile** tiles, int nrOfTiles);
	void update(Ray raycast[] = nullptr, int nrOfRays = 0);
};