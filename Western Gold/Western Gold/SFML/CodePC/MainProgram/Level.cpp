#include <fstream>
#include <string>
#include "Level.h"

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
		for (int i = 0; i < nrOFEnemies; ++i) {
			file.getline(buf, 10);
			int nrOfPatrollPoints = std::stoi(buf);
			PatrollPoints* points = new PatrollPoints(nrOfPatrollPoints);
			for (int k = 0; k < nrOfPatrollPoints; ++k) {
				sf::Vector2i point;
				int x;
				int y;
				file.getline(buf, 10, ' ');
				x = std::stoi(buf);
				file.getline(buf, 10);
				y = std::stoi(buf);

				point = grid->getTiles()[y][x].getWorldPos();
				points->add(point);
			}
			Enemy* enm = new Enemy(rm, 45, grid, player);
			enm->setPosition(static_cast<sf::Vector2f>(points->getPoints()[0]));
			enm->setPatrollPoints(points);
			handler.add(enm);
			file.getline(buf, 10);
		}
	}


	file.close();
}
