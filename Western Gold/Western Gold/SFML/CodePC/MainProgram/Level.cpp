#include <fstream>
#include <string>
#include "Level.h"
#include "Player.h"

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

void Level::drawLevel(sf::RenderWindow& window, Player* player) const
{
	float epsilon = 715.f;
	//grid->renderGrid(window);
	for (unsigned int x = 0; x < grid->getGridSize().x; ++x) {
		for (unsigned int y = 0; y < grid->getGridSize().y; ++y) {
			float distance = getDistance(player->getPosition(),
				static_cast<sf::Vector2f>(grid->getTiles()[y][x].getWorldPos()));

			if (distance <= epsilon) {
				window.draw(*grid->getTiles()[y][x].getSprite());
			}
		}
	}
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

float Level::getDistance(sf::Vector2f a, sf::Vector2f b) const
{
	float diffX = b.x - a.x;
	float diffY = b.y - a.y;
	float distance = sqrt((diffX * diffX) + (diffY * diffY));
	return distance;
}
