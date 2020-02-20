#include "Pathfinding.h"
#include <vector>
#include "Tile.h"
#include "Grid.h"

Pathfinding::Pathfinding(Grid* grid) {
	this->grid = grid;
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
			if (open[i]->getTCost() < currentTile->getTCost()) {
				currentTile = open[i];
			}
		}
	}
}
