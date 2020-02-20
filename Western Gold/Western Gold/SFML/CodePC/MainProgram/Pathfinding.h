#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include <vector>
class Pathfinding
{
public:
	Pathfinding(Grid* grid);
	~Pathfinding();
	void findPath(sf::Vector2i start, sf::Vector2i end);
	

private:
	Grid* grid;
	void removeElementFromVector(std::vector<tile*> &vec,tile* t);
	bool isInVector(std::vector<tile*> &vec, tile* t);
	int getDistance(tile* t1, tile* t2) const;
};

