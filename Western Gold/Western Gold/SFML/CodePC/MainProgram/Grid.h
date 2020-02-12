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
	//debug
	void renderGrid(sf::RenderWindow& window) const;
private:
	tile** tiles;
	sf::Vector2u worldSize;
	float nodeSize;

private:
	void initGrid(ResourceManager* rm, sf::Image* level);
	void setTileSize(ResourceManager* rm);
};

