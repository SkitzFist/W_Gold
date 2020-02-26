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
	tile* getNextTile();

	void clearPath();

private:
	Grid* grid;
	std::vector<tile*> path;
	void removeElementFromVector(std::vector<tile*> &vec,tile* t);
	bool isInVector(std::vector<tile*> &vec, tile* t);
	int getDistance(tile* t1, tile* t2) const;
	void retracePath(tile* startTile, tile* endTile);
};

