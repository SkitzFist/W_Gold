#include "Level.h"

Level::Level(ResourceManager* rm, const sf::Image level)
{
	//config

	//setup
	grid = new Grid(rm, level);
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

void Level::drawLevel(sf::RenderWindow& window) const
{
	grid->renderGrid(window);
	//renderObjects(window);
}
