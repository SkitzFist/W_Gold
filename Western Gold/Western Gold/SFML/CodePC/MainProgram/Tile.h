#pragma once
#include "GameObject.h"
#include "Ray.h"

class Tile : public GameObject{
private:
	bool collide;
	Ray rayCast;
public:
	Tile(sf::Texture* texture, ResourceManager * rm, float xPos, float yPos);
	//Have Player in class
	void update(DeltaTime time);
};