#include "Tile.h"

Tile::Tile(sf::Texture *texture, ResourceManager *rm, float xPos, float yPos):
	GameObject(texture,rm)
{
	this->collide = true;
	setPosition(xPos, yPos);
}

void Tile::update(DeltaTime time)
{
	if (collide) {

	}
}
