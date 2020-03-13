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
	grid->renderGrid(window);
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
