#include "Pathfinding.h"
#include "Tile.h"
#include "Grid.h"

//debug
#include <iostream>

Pathfinding::Pathfinding(Grid* grid) {
	this->grid = grid;

}

Pathfinding::~Pathfinding()
{
	path.erase(path.begin(), path.end());
}

void Pathfinding::findPath(sf::Vector2i start, sf::Vector2i end)
{
	std::vector<tile*> open;
	std::vector<tile*> closed;

	tile* startTile = grid->getTileFromWorldPos(start);
	tile* endTile = grid->getTileFromWorldPos(end);

	if (endTile == nullptr) {
		std::cout << "NULL" << std::endl;
	}

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
			retracePath(startTile, endTile);
			break;
		}

		std::vector<tile*> surroundingTiles = grid->getSurroundingTiles(currentTile);


		for (int i = 0; i < surroundingTiles.size(); ++i) {
			if(!(surroundingTiles[i]->getIsWalkable())
				|| isInVector(closed, surroundingTiles[i])) {
				continue;
			}

			int newMovementCostToNeighbour = currentTile->getSCost() + getDistance(currentTile, surroundingTiles[i]);
			if (newMovementCostToNeighbour < surroundingTiles[i]->getSCost()
				|| !(isInVector(open, surroundingTiles[i]))) {
				surroundingTiles[i]->setSCost(newMovementCostToNeighbour);
				surroundingTiles[i]->setECost(getDistance(surroundingTiles[i], endTile));
				surroundingTiles[i]->setParent(currentTile);

				if (!(isInVector(open, surroundingTiles[i]))) {
					open.push_back(surroundingTiles[i]);
				}
			}
		}
		surroundingTiles.clear();
	}
	open.clear();
	closed.clear();
}

void Pathfinding::findPath(tile* start, tile* end)
{
	std::vector<tile*> open;
	std::vector<tile*> closed;

	tile* startTile = start;
	tile* endTile = end;

	if (endTile == nullptr) {
		std::cout << "NULL" << std::endl;
	}

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
			retracePath(startTile, endTile);
			break;
		}

		std::vector<tile*> surroundingTiles = grid->getSurroundingTiles(currentTile);


		for (int i = 0; i < surroundingTiles.size(); ++i) {
			if (!(surroundingTiles[i]->getIsWalkable())
				|| isInVector(closed, surroundingTiles[i])) {
				continue;
			}

			int newMovementCostToNeighbour = currentTile->getSCost() + getDistance(currentTile, surroundingTiles[i]);
			if (newMovementCostToNeighbour < surroundingTiles[i]->getSCost()
				|| !(isInVector(open, surroundingTiles[i]))) {
				surroundingTiles[i]->setSCost(newMovementCostToNeighbour);
				surroundingTiles[i]->setECost(getDistance(surroundingTiles[i], endTile));
				surroundingTiles[i]->setParent(currentTile);

				if (!(isInVector(open, surroundingTiles[i]))) {
					open.push_back(surroundingTiles[i]);
				}
			}
		}
		surroundingTiles.clear();
	}
	open.clear();
	closed.clear();
}

tile* Pathfinding::getNextTile()
{
	tile* t = nullptr;
	if (path.size() > 0) {
		size_t index = (path.size() - 1);
		t = path[index];
		path.pop_back();		
	}
	return t;
}

void Pathfinding::clearPath()
{
	path.clear();
}

void Pathfinding::retracePath(tile* startTile, tile* endTile) {
	path.clear();
	tile* currentTile = endTile;
	//sf::Texture* texture = new sf::Texture(); // TODO:: Remove this, only for debugging.
	//texture->loadFromFile("../Textures/tile_ok.png");
	while (currentTile != startTile) {
		path.push_back(currentTile);
		/*currentTile->setSprite(texture);*/
		currentTile = currentTile->getParent();
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
	return isInVector;
}

int Pathfinding::getDistance(tile* t1, tile* t2) const
{
	int rv = 0;

	int dstx = abs(t1->getGridPos().x - t2->getGridPos().x);
	int dsty = abs(t1->getGridPos().y - t2->getGridPos().y);

	if (dstx > dsty) {
		rv = 14 * dsty + 10 * (dstx - dsty);
	}
	else{
		rv = 14 * dstx + 10 * (dsty - dstx);
	}

	return rv;
}
