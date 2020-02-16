#pragma once
#include "Tile.h"
#include "Player.h"
//#include "Gold"
#include "GetDistance.h"

class Collision {
private:
	GameObject* gameObjects;
	tile* tiles;
	int nrOfTiles;
	void checkCollision();
	void checkCollisionRays(Ray raycast[], int nrOfRays = 0);
	//if gameobject is on the right side of tiles
	bool rightSide(GameObject*	gameObject, tile* tiles);
	bool leftSide(GameObject*	gameObject, tile* tiles);
	bool topSide(GameObject*	gameObject, tile* tiles);
	bool botSide(GameObject*	gameObject, tile* tiles);
	//when joel is done with tiles
	//bool rLeft(	Entity* player, tile Tile);
	//bool rRight(Entity* player, tile Tile);
	//bool rTop(	Entity* player, tile Tile);
	//bool rBot(	Entity* player, tile Tile);
public:
	Collision();
	virtual ~Collision();
	void setUpCollision(GameObject* player, tile* tiles, int nrOfTiles);
	void update(Ray raycast[] = nullptr, int nrOfRays = 0);
};