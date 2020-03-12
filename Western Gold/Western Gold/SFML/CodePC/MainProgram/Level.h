#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "ResourceManager.h"
#include "EnemyHandler.h"

class Level
{
public:
	Level(ResourceManager* rm, sf::Image* level);
	~Level();
	Grid* getGrid() const;
	tile** getTiles() const;
	void drawLevel(sf::RenderWindow &window) const;
	void placeEnemies(Player* player, EnemyHandler& handler);
	
private:
	Grid* grid;
	ResourceManager* rm;
};

