#pragma once
#include "Node.h"
#include "ResourceManager.h"

class Grid
{
public:
	Grid(ResourceManager* rm, const sf::Image& level);
	~Grid();

	//debug
	void renderGrid(sf::RenderWindow& window) const;

private:
	Node** grid;
	sf::Vector2u worldSize;
	float nodeSize;

private:
	void initGrid(ResourceManager* rm, const sf::Image& level);
};

