#include "Grid.h"
#include "Utils.h"

//debug
#include <iostream>

Grid::Grid(ResourceManager* rm, sf::Image*level)
{
	//Config
	tileSize = static_cast<float>(rm->getTile_White()->getSize().x);
	//Setup
	gridSize = {level->getSize().x, level->getSize().y};
	worldSize = {
		static_cast<int>(tileSize) * gridSize.x,
		static_cast<int>(tileSize) * gridSize.y
	};

	tiles = allocateTwoDimensionalArray<tile>(gridSize.x, gridSize.x);
	initGrid(rm,level);
	//Debug
	
}

Grid::~Grid()
{
	deallocateTwoDimensionalArray(tiles, gridSize.x);
}

tile** Grid::getTiles() const
{
	return tiles;
}

tile* Grid::getTileFromWorldPos(sf::Vector2i pos)
{
	tile* t = nullptr;
	if (isInsideWorld(pos)) {	

		float posX = pos.x * 10.f;
		float posY = pos.y * 10.f;
		float worldSizeX = worldSize.x * 10.f;
		float worldSizeY = worldSize.x * 10.f;
		double percentX = posX / worldSizeX;
		double percentY = posY / worldSizeY;
		
		int x = static_cast<int>(gridSize.x * percentX);
		int y = static_cast<int>(gridSize.y * percentY);

		if (x >= 0 
            && x < (int)gridSize.x
			&& y >= 0
			&& y < (int)gridSize.y) {
			t = &tiles[y][x];
		}
	}
	return t;
}

sf::Vector2u Grid::getGridSize() const
{
	return gridSize;
}

void Grid::renderGrid(sf::RenderWindow& window) const
{
	for (unsigned int x = 0; x < gridSize.x; ++x) {
		for (unsigned int y = 0; y < gridSize.x; ++y) {

			window.draw(*tiles[y][x].getSprite());
		}
	}
}

std::vector<tile*> Grid::getSurroundingTiles(tile* t)
{
	std::vector<tile*> neighbours;

	for (int x = -1; x <= 1; ++x) {
		for (int y = -1; y <= 1; ++y) {
			if (x == y || x == -y) {
				continue;
			}

			int checkX = t->getGridPos().x + x;
			int checkY = t->getGridPos().y + y;

			if (checkX >= 0 && checkX < (int)gridSize.x
				&& checkY >= 0 && checkY <(int) gridSize.y) {
				if (tiles[checkY][checkX].getIsWalkable()) {
					neighbours.push_back(&tiles[checkY][checkX]);
				}
			}
		}
	}

	return neighbours;
}

void Grid::initGrid(ResourceManager* rm,sf::Image* level)
{
	sf::Color whiteTile = { 255,255,255 };
	sf::Color blackTile = { 0,0,0 };

	sf::Vector2f pos = {-tileSize /2 ,-tileSize /2};
	
	for (unsigned int x = 0; x < gridSize.x; ++x) {
		pos.x += tileSize;
		pos.y = -tileSize /2;
		for (unsigned int y = 0; y < gridSize.y; ++y) {
			pos.y += tileSize;

			sf::Color pixelInlevel = level->getPixel(x, y);
			if (pixelInlevel == whiteTile) {
				
				tiles[y][x].setSprite(rm->getTile_White());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(true);
				tiles[y][x].setGridPos(sf::Vector2i(x, y));
			}
			else if (pixelInlevel == blackTile) {
				tiles[y][x].setSprite(rm->getTile_Black());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(false);
				tiles[y][x].setGridPos(sf::Vector2i(x, y));
			}
		}
	}
}

bool Grid::isInsideWorld(sf::Vector2i pos)
{
	bool isInside = false;

	if (pos.x > 0
		&& pos.x < static_cast<int>(worldSize.x)
		&& pos.y > 0
		&& pos.y < static_cast<int>(worldSize.y)) {
		isInside = true;
	}

	return isInside;
}
