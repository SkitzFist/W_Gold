#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "ResourceManager.h"
#include "EnemyHandler.h"
#include "GoldHandler.h"

struct Index
{
	int x;
	int y;
};

enum xDir {
	LEFT = -1,
	RIGHT = 1
};

enum yDir
{
	UP = -1,
	down = 1
};


class Level
{
public:
	Level(ResourceManager* rm, sf::Image* level);
	~Level();
	Grid* getGrid() const;
	tile** getTiles() const;
	void drawLevel(sf::RenderWindow &window) const;
	
	void placeEnemies(Player* player, EnemyHandler& handler);
	void placeGold(GoldHandler& handler);
	
private:
	Grid* grid;
	ResourceManager* rm;

	//debug
	tile** drawTiles;
	int nrOfDrawTiles;
	int nrOfTilesOnScreen;
};

