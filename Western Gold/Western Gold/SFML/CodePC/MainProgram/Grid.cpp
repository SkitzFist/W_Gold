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

	tiles = allocateTwoDimensionalArray<tile>(gridSize.x, gridSize.y);
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
	float percentX = (pos.x + worldSize.x / 2.f) / worldSize.x;
	float percentY = (pos.y + worldSize.y / 2.f) / worldSize.y;
	
	int x = static_cast<int>( std::round(gridSize.x - 1) * percentX);
	int y = static_cast<int>(std::round(gridSize.y - 1) * percentY);

	if (&tiles[y][x] != nullptr) {
		t = &tiles[y][x];
	}

	return t;
}

sf::Vector2u Grid::getGridSize() const
{
	return gridSize;
}

//debug


void Grid::renderGrid(sf::RenderWindow& window) const
{
	for (unsigned int x = 0; x < gridSize.x; ++x) {
		for (unsigned int y = 0; y < gridSize.y; ++y) {

			window.draw(*tiles[y][x].getSprite());
		}
	}
}

void Grid::initGrid(ResourceManager* rm,sf::Image* level)
{
	sf::Color whiteTile = { 255,255,255 };
	sf::Color blackTile = { 0,0,0 };

	sf::Vector2f pos = {-tileSize /2 , -tileSize /2};
	
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
			}
			else if (pixelInlevel == blackTile) {
				tiles[y][x].setSprite(rm->getTile_Black());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(false);
			}
		}
	}
}