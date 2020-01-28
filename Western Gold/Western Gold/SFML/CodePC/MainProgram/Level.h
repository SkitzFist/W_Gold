#pragma once
#include "Grid.h"
#include "ResourceManager.h"

class Level
{
public:
	Level(ResourceManager* rm, const sf::Image level);
	~Level();
	Grid* getGrid() const;

private:
	Grid* grid;
};

