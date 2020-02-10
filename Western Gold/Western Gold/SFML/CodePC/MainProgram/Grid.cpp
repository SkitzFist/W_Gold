#include "Grid.h"
#include "Utils.h"

//debug
#include <iostream>

Grid::Grid(ResourceManager* rm, sf::Image*level)
{
	//Config
	setTileSize(rm);

	//Setup
	worldSize = {level->getSize().x, level->getSize().y};
	grid = allocateTwoDimensionalArray<tile>(worldSize.x, worldSize.y);
	initGrid(rm,level);
	//Debug
}

Grid::~Grid()
{
	deallocateTwoDimensionalArray(grid, worldSize.x);
}

//debug

void Grid::renderGrid(sf::RenderWindow& window) const
{
	for (unsigned int x = 0; x < worldSize.x; ++x) {
		for (unsigned int y = 0; y < worldSize.y; ++y) {

			window.draw(*grid[y][x].getSprite());
		}
	}
}

void Grid::initGrid(ResourceManager* rm,sf::Image* level)
{
	sf::Color whiteTile = { 255,255,255 };
	sf::Color blackTile = { 0,0,0 };
	sf::Vector2f pos = {-nodeSize , -nodeSize};
	
	for (unsigned int x = 0; x < worldSize.x; ++x) {
		pos.x += nodeSize;
		pos.y = -nodeSize;
		for (unsigned int y = 0; y < worldSize.y; ++y) {
			pos.y += nodeSize;

			sf::Color pixelInlevel = level->getPixel(x, y);
			if (pixelInlevel == whiteTile) {
				
				grid[y][x].setSprite(rm->getTile_White());
				grid[y][x].setWorldPos(pos);
				grid[y][x].setIsWalkable(true);
			}
			else if (pixelInlevel == blackTile) {
				grid[y][x].setSprite(rm->getTile_Black());
				grid[y][x].setWorldPos(pos);
				grid[y][x].setIsWalkable(true);
			}
		}
	}
}

void Grid::setTileSize(ResourceManager* rm)
{
	sf::Sprite sprite;
	sprite.setTexture(*rm->getTile_White());
	nodeSize = sprite.getGlobalBounds().width;
}
