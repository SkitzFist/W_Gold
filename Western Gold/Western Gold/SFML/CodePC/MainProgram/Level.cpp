#include "Level.h"
#include <vector>

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

std::vector<tile*> Level::getTilesOnScreen()
{
	std::vector<tile*> tiles;
	int nrOf = 0;
	static int count = 0;
	for (unsigned int x = 0; x < grid->getGridSize().x; ++x) {
		for (unsigned int y = 0; y < grid->getGridSize().y; ++y) {

			/*if (rm->getWindow()->getView().getViewport().contains(
				static_cast<sf::Vector2f>(grid->getTiles()[y][x].getWorldPos()))) {
				tiles.push_back(&grid->getTiles()[y][x]);
				++count;
			}*/

			if (grid->getTiles()[y][x].getSprite()->getGlobalBounds().intersects(
				rm->getWindow()->getView().getViewport())) {
				++count;
			}
			
		}
	}
	std::cout << count << std::endl;

	return tiles;
}
