#include "Tile.h"

Tile::Tile(sf::Texture *texture, float xPos, float yPos):
	GameObject(texture)
{
	this->collide = true;
	setPosition(xPos, yPos);
}

void Tile::update(DeltaTime time)
{
	if (collide) {

	}
}
