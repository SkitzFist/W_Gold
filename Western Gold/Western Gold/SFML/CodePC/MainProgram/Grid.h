#pragma once
#include "tile.h"
#include "ResourceManager.h"
#include <wincrypt.h>

class Grid
{
public:
	Grid(ResourceManager* rm, sf::Image* level);
	~Grid();
	tile** getTiles() const;
	tile* getTileFromWorldPos(sf::Vector2i pos);
	sf::Vector2u getGridSize() const;
	//debug
	void renderGrid(sf::RenderWindow& window) const;
private:
	tile** tiles;
	sf::Vector2u gridSize;
	sf::Vector2u worldSize;
	float tileSize;

private:
	void initGrid(ResourceManager* rm, sf::Image* level);
};

