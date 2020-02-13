#pragma once
#include "Grid.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>

class Level
{
public:
	Level(ResourceManager* rm, sf::Image* level);
	~Level();
	Grid* getGrid() const;
	tile** getTiles() const;
	void drawLevel(sf::RenderWindow &window) const;
	tile* getTilesOnScreen();
private:
	Grid* grid;
	ResourceManager* rm;
};

