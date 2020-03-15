#include <fstream>
#include <string>
#include "Level.h"
#include "Player.h"

//debug
#include <iostream>

Level::Level(ResourceManager* rm, sf::Image* level)
{
	//config

	//setup
	grid = new Grid(rm, level);
	this->rm = rm;
	//debug
	nrOfTilesOnScreen = 1500;
	nrOfDrawTiles = 0;
	drawTiles = new tile * [nrOfTilesOnScreen];
}

Level::~Level()
{
	delete grid;
	delete[] drawTiles;
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

	sf::Vector2i cameraPos = sf::Vector2i(static_cast<int>(rm->getView()->getCenter().x),
		static_cast<int>(rm->getView()->getCenter().y));
	tile* middleTile = this->grid->getTileFromWorldPos(cameraPos);
	if (middleTile != nullptr) {
		int offset = 17;
		for (int x = middleTile->getGridPos().x - offset; x < middleTile->getGridPos().x + offset; x++) {
			for (int y = middleTile->getGridPos().y - offset; y < middleTile->getGridPos().y + offset; y++) {
				if (x > 0 && x < (int)grid->getGridSize().x && y > 0 && y < (int)grid->getGridSize().y) {
					if (grid->getTiles()[y][x].getWannaDraw()) {
						window.draw(*grid->getTiles()[y][x].getSprite());
					}
				}
			}
		}
	}
}

void Level::placeEnemies(Player* player, EnemyHandler& handler)
{
	std::ifstream file("../Levels/level_01_enemies.txt");

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

void Level::placeGold(GoldHandler& handler)
{
	std::ifstream file("../Levels/level_01_gold.txt");
	char buf[10];
	if (file.is_open()) {
		file.getline(buf, 10);
		int nrOfGold = std::stoi(buf);
		for (int i = 0; i < nrOfGold; ++i) {
			file.getline(buf, 10, ' ');
			int x = std::stoi(buf);
			file.getline(buf, 10);
			int y = std::stoi(buf);
			sf::Vector2i pos = grid->getTiles()[y][x].getWorldPos();
			Gold* gold = new Gold(rm, static_cast<float>(pos.x), static_cast<float>(pos.y));
			handler.add(gold);
		}
	}
	file.close();
}