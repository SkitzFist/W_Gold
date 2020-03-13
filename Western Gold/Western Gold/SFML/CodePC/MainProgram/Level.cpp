#include <fstream>
#include <string>
#include "Level.h"

//debug
#include <iostream>
Level::Level(ResourceManager* rm, sf::Image* level)
{
	//config

	//setup
	grid = new Grid(rm, level);
	this->rm = rm;
	//debug
}

Level::~Level()
{
	delete grid;
}

Grid* Level::getGrid() const
{
	return grid;
}

tile** Level::getTiles() const
{

	return grid->getTiles();
}

void Level::drawLevel(sf::RenderWindow& window) const
{
	//grid->renderGrid(window);
	sf::Vector2i cameraPos = sf::Vector2i(rm->getView()->getCenter().x, rm->getView()->getCenter().y);
	tile* middleTile = this->grid->getTileFromWorldPos(cameraPos);
	//sf::Vector2i 
	int offset = 17;
	for (int x = middleTile->getGridPos().x - offset; x < middleTile->getGridPos().x + offset; x++) {
		for (int y = middleTile->getGridPos().y - offset; y < middleTile->getGridPos().y + offset; y++) {
			if (x > 0 && x < grid->getGridSize().x && y > 0 && y < grid->getGridSize().y) {
				window.draw(*grid->getTiles()[y][x].getSprite());
			}
		}
	}
		
		
	//renderObjects(window);
}

void Level::placeEnemies(Player* player, EnemyHandler& handler)
{
	std::ifstream file("../Levels/level_01.txt");

	char del = '-';
	int nrOFEnemies = 0;
	char buf[10];
	if (file.is_open()) {
		file.getline(buf, 10);
		nrOFEnemies = std::stoi(buf);
		std::cout << nrOFEnemies << std::endl;

		for (int i = 0; i < nrOFEnemies; ++i) {
			file.getline(buf, 10);
			int nrOfPatrollPoints = std::stoi(buf);
			PatrollPoints* points = new PatrollPoints(nrOfPatrollPoints);
			for (int y = 0; y < nrOfPatrollPoints; ++y) {
				sf::Vector2i point;
				file.getline(buf, 10, ' ');
				point.x = std::stoi(buf);
				file.getline(buf, 10);
				point.y = std::stoi(buf);
				points->add(point);
				std::cout << point.x << "." << point.y << std::endl;
			}
			file.getline(buf, 10);
		}
	}


	file.close();
}
