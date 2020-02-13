#pragma once
#include "Tile.h"
#include "Player.h"
//#include "Gold"
#include "Ray.h"
#include "GetDistance.h"

class Collision {
private:
	GameObject* gameObjects;
	tile* tiles;
	void checkCollision();
	//if gameobject is on the right side of tiles
	bool rightSide(GameObject*	gameObject, tile* tiles);
	bool leftSide(GameObject*	gameObject, tile* tiles);
	bool topSide(GameObject*	gameObject, tile* tiles);
	bool botSide(GameObject*	gameObject, tile* tiles);
public:
	Collision();
	void setUpCollision(GameObject* player, tile* tiles);
	void update(Ray raycast[] = nullptr);
};