#include "Pathfinding.h"
#include "Tile.h"
#include "Grid.h"

//debug
#include <iostream>

Pathfinding::Pathfinding(Grid* grid) {
	this->grid = grid;

	int dst = getDistance(&grid->getTiles()[0][0], &grid->getTiles()[4][6]);
	std::cout << dst;
}

Pathfinding::~Pathfinding()
{
}

void Pathfinding::findPath(sf::Vector2i start, sf::Vector2i end)
{
	std::vector<tile*> open;
	std::vector<tile*> closed;

	tile* startTile = grid->getTileFromWorldPos(start);
	tile* endTile = grid->getTileFromWorldPos(end);

	open.push_back(startTile);

	while (open.size() > 0)
	{
		tile* currentTile = open[0];
		for (int i = 0; i < open.size(); ++i) {
			if (open[i]->getTCost() < currentTile->getTCost()
				|| open[i]->getTCost() == currentTile->getTCost()
				&& open[i]->getECost() < currentTile->getECost()) {
				currentTile = open[i];
			}
		}

		removeElementFromVector(open, currentTile);
		closed.push_back(currentTile);
		if (currentTile == endTile) {
			return; //come back to this later
		}

		std::vector<tile*> surroundingTiles = grid->getSurroundingTiles(currentTile);

		for (int i = 0; i < surroundingTiles.size(); ++i) {
			if(!(surroundingTiles[i]->getIsWalkable())
				|| isInVector(closed, surroundingTiles[i])) {
				continue;
			}
		}
	}
}

void Pathfinding::removeElementFromVector(std::vector<tile*>& vec, tile* t)
{
	int index = -1;
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == t) {
			index = i;
		}
	}
	if (!(index == -1)) {
		vec.erase(vec.begin()+index);
	}
}

bool Pathfinding::isInVector(std::vector<tile*>& vec, tile* t)
{
	bool isInVector = false;
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == t) {
			isInVector = true;
		}
	}
	return false;
}

int Pathfinding::getDistance(tile* t1, tile* t2) const
{
	int rv = 0;
	int dstX = abs(t1->getGridPos().x - t2->getGridPos().x);
	int dstY = abs(t1->getGridPos().y - t2->getGridPos().y);

	if (dstX > dstY) {
		rv = 14 * dstY + 10 * (dstX - dstY);
	}
	else{
		rv = 14 * dstX + 10 * (dstY - dstX);
	}

	return rv;
}
