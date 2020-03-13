#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "ResourceManager.h"
#include "EnemyHandler.h"

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
	void drawLevel(sf::RenderWindow &window, Player* player) const;
	
	void placeEnemies(Player* player, EnemyHandler& handler);
	//Experimental
	void findDrawTiles(Player* player);
	void experimentalDrawLevel(sf::RenderWindow& window) const;
private:
	Grid* grid;
	ResourceManager* rm;
	float getDistance(sf::Vector2f a, sf::Vector2f b) const;

	//debug
	tile** drawTiles;
	int nrOfDrawTiles;
	int nrOfTilesOnScreen;

	void addTiles(Index current, Index dir, Index childDir, int length, int currentLength);
	void addTileChild(Index Current, Index dir, int length, int currentLength);
};

