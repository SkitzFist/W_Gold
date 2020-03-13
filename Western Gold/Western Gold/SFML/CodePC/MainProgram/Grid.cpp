#include "Grid.h"
#include "Utils.h"

//debug
#include <iostream>

Grid::Grid(ResourceManager* rm, sf::Image*level)
{
	//Config
	tileSize = static_cast<float>(rm->getTile_White()->getSize().x);

	//Setup
	nrOfWalkableTiles = 0;
	nrOfNotWalkableTiles = 0;
	gridSize = {level->getSize().x, level->getSize().y};
	worldSize = {
		static_cast<int>(tileSize) * gridSize.x,
		static_cast<int>(tileSize) * gridSize.y
	};

	tiles = allocateTwoDimensionalArray<tile>(gridSize.y, gridSize.x);
	initGrid(rm,level);
	//Debug
	
}

Grid::~Grid()
{
	deallocateTwoDimensionalArray(tiles, gridSize.y);
}

tile** Grid::getTiles() const
{
	return tiles;
}

tile* Grid::getTileFromWorldPos(sf::Vector2i pos)
{
	tile* t = nullptr;
	if (isInsideWorld(pos)) {	

		float posX = static_cast<float>(pos.x);
		float posY = static_cast<float>(pos.y);
		float worldSizeX = static_cast<float>(worldSize.x);
		float worldSizeY = static_cast<float>(worldSize.y);
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
		for (unsigned int y = 0; y < gridSize.y; ++y) {
			if (tiles[y][x].getWannaDraw()) {
				window.draw(*tiles[y][x].getSprite());
			}
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

int Grid::getNrOfWalkableTiles() const
{
	return nrOfWalkableTiles;
}

int Grid::getNrOfNotWalkableTiles() const
{
	return nrOfNotWalkableTiles;
}

float Grid::getTileSize() const
{
	return tileSize;
}

void Grid::initGrid(ResourceManager* rm,sf::Image* level)
{
	sf::Color floor = { 118,85,4 };
	sf::Color sand = { 154,156,72 };
	sf::Color wall = { 0,0,0 };

	sf::Vector2f pos = {-tileSize /2 ,-tileSize /2};
	
	for (unsigned int x = 0; x < gridSize.x; ++x) {
		pos.x += tileSize;
		pos.y = -tileSize /2;
		for (unsigned int y = 0; y < gridSize.y; ++y) {
			pos.y += tileSize;

			sf::Color pixelInlevel = level->getPixel(x, y);
			if (pixelInlevel == sand) {
				++nrOfWalkableTiles;
				tiles[y][x].setSprite(rm->getTile_sand());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(true);
				tiles[y][x].setGridPos(sf::Vector2i(x, y));
			}
			else if (pixelInlevel == floor) {
				++nrOfWalkableTiles;
				tiles[y][x].setSprite(rm->getTile_floor());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(true);
				tiles[y][x].setGridPos(sf::Vector2i(x, y));
			}
			else if (pixelInlevel == wall) {
				++nrOfNotWalkableTiles;
				tiles[y][x].setSprite(rm->getTile_wall());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(false);
				tiles[y][x].setGridPos(sf::Vector2i(x, y));
			}
		}
	}
	/*
	about what we should do later
	arr1[][];
	arr2[][];
	for(int x = 0; x < nrArr1x; x++){
	for(int y = 0; y < nrArr1y; y++){
		tiles[x][y].getSprite(arr[x][y])//in some kind of way
		tiles[x][y].setWoldPos(gridSize.x*x, gridSize.y*y)//pos can be set up over this
		tiles[x][y].setIsWalkable(false);
		tiles[x][y].setGridPos(x,y);
	}
	}
	//and then the same for arr2 but tiles[x][y].setIsWalkable(true);
	*/
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
