#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
class Pathfinding
{
public:
	Pathfinding(Grid* grid);
	~Pathfinding();
	void findPath(sf::Vector2i start, sf::Vector2i end);

private:
	Grid* grid;
};

