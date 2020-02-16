#include "Level.h"

//debug
#include <iostream>
Level::Level(ResourceManager* rm, sf::Image* level)
{
	//config

	//setup
	grid = new Grid(rm, level);
	this->rm = rm;
	//debug
}

Level::~Level()
{
	delete grid;
}

Grid* Level::getGrid() const
{
	return grid;
}

tile** Level::getTiles() const
{
	
	return grid->getTiles();
}

void Level::drawLevel(sf::RenderWindow& window) const
{
	grid->renderGrid(window);
	//renderObjects(window);
}

tile* Level::getTilesOnScreen()
{
	tile* tiles = nullptr;
	int nrOf = -1;
	static int count = 0;
	for (unsigned int x = 0; x < grid->getGridSize().x; ++x) {
		for (unsigned int y = 0; y < grid->getGridSize().y; ++y) {
			tiles = &grid->getTiles()[y][x];
			if (tiles->getSprite()->getGlobalBounds().intersects(rm->getWindow()->getView().getViewport())) {
				std::cout << "hello" << std::endl;
			}
			
		}
	}
	std::cout << count << std::endl;

	return tiles;
}
