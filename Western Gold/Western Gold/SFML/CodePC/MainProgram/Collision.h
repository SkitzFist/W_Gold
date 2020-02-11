#pragma once
#include "Tile.h"
#include "Player.h"
//#include "Gold"
#include "Ray.h"

class Collision {
private:
	GameObject* gameObjects;
	tile* tiles;
	void checkCollision();
	bool rightSide(GameObject* player, tile* tiles);
	bool leftSide(GameObject* player, tile* tiles);
	bool topSide(GameObject* player, tile* tiles);
	bool botSide(GameObject* player, tile* tiles);
public:
	Collision();
	void setUpCollision(GameObject* player, tile* tiles);
	void update(Ray raycast[] = nullptr);
};