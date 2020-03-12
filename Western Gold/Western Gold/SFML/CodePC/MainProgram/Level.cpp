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
		while (!(file.eof()))
		{
			file.getline(buf, 10, ' ');
			int size = std::stoi(buf);
			std::cout << size << std::endl;
			Enemy* enm = new Enemy(rm, 90, grid, player);
			PatrollPoints* points = new PatrollPoints(size);
			for (int i = 0; i < size; ++i) {
				file.getline(buf, 10);
				int x = std::stoi(buf);
				file.getline(buf, 10);
				int y = std::stoi(buf);
				std::cout << x << "." << y << std::endl;
				sf::Vector2i point = { x, y };
				points->add(point);
			}
		}
	}


	file.close();
}
