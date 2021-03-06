#pragma once
#include "tile.h"
#include "ResourceManager.h"
#include <vector>
//?
#include <wincrypt.h>


class Grid
{
public:
	Grid(ResourceManager* rm, sf::Image* level);
	~Grid();
	tile** getTiles() const;
	tile* getTileFromWorldPos(sf::Vector2i pos);
	sf::Vector2u getGridSize() const;
	std::vector<tile*> getSurroundingTiles(tile* t);
	int getNrOfWalkableTiles() const;
	int getNrOfNotWalkableTiles() const;
	float getTileSize()const;
	tile* getTileFromIndex(int x, int y);
	sf::Vector2f getWorldPosFromIndex(int x, int y);
private:
	tile** tiles;
	sf::Vector2u gridSize;
	sf::Vector2u worldSize;
	float tileSize;

	int nrOfWalkableTiles;
	int nrOfNotWalkableTiles;
	void initGrid(ResourceManager* rm, sf::Image* level);
	bool isInsideWorld(sf::Vector2i pos);
};

