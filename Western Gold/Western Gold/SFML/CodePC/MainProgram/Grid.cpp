#include "Grid.h"
#include "Utils.h"

Grid::Grid(ResourceManager* rm, const sf::Image level)
{
	//Config
	nodeSize = rm->getTile_blue()->getSize().x;

	//Setup
	worldSize = {level.getSize().x, level.getSize().y};
	Utils util;
	grid = util.allocateTwoDimensionalArray<Node>(worldSize.x, worldSize.y);
	

	//Debug
}

Grid::~Grid()
{
	Utils util;
	util.deallocateTwoDimensionalArray(grid);
}

//debug

void Grid::renderGrid(sf::RenderWindow& window) const
{
	for (unsigned int x = 0; x < worldSize.x; ++x) {
		for (unsigned int y = 0; y < worldSize.y; ++y) {
			window.draw(grid[x][y].getSprite());
		}
	}
}
