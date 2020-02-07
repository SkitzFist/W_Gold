#include "Grid.h"
#include "Utils.h"

//debug
#include <iostream>

Grid::Grid(ResourceManager* rm, const sf::Image& level)
{
	//Config
	sf::Sprite sprite;
	sprite.setTexture(*rm->getTile_green());
	nodeSize = sprite.getGlobalBounds().width;

	//Setup
	worldSize = {level.getSize().x, level.getSize().y};
	grid = allocateTwoDimensionalArray<Node>(worldSize.x, worldSize.y);
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

			window.draw(grid[y][x].getSprite());
		}
	}
}

void Grid::initGrid(ResourceManager* rm, const sf::Image& level)
{
	sf::Color greenTile = { 43,227,12 };
	sf::Color blueTile = { 12,18,227 };
	sf::Vector2f pos = {-nodeSize , -nodeSize};
	
	for (unsigned int x = 0; x < worldSize.x; ++x) {
		pos.x += nodeSize;
		pos.y = -nodeSize;
		for (unsigned int y = 0; y < worldSize.y; ++y) {
			pos.y += nodeSize;

			sf::Color pixelInlevel = level.getPixel(x, y);
			if (pixelInlevel == greenTile) {
				
				grid[y][x].setSprite(rm->getTile_green());
				grid[y][x].setWorldPos(pos);
				grid[y][x].setIsWalkable(true);
			}
			else if (pixelInlevel == blueTile) {
				grid[y][x].setSprite(rm->getTile_blue());
				grid[y][x].setWorldPos(pos);
				grid[y][x].setIsWalkable(true);
			}
		}
	}
}
