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

void Level::drawLevel(sf::RenderWindow& window, Player* player) const
{
<<<<<<< HEAD
	//grid->renderGrid(window);
	sf::Vector2i cameraPos = sf::Vector2i(rm->getView()->getCenter().x, rm->getView()->getCenter().y);
	tile* middleTile = this->grid->getTileFromWorldPos(cameraPos);
	//sf::Vector2i 
	int offset = 17;
	for (int x = middleTile->getGridPos().x - offset; x < middleTile->getGridPos().x + offset; x++) {
		for (int y = middleTile->getGridPos().y - offset; y < middleTile->getGridPos().y + offset; y++) {
			if (x > 0 && x < grid->getGridSize().x && y > 0 && y < grid->getGridSize().y) {
=======
	float epsilon = 715.f;
	//grid->renderGrid(window);
	for (unsigned int x = 0; x < grid->getGridSize().x; ++x) {
		for (unsigned int y = 0; y < grid->getGridSize().y; ++y) {
			float distance = getDistance(player->getPosition(),
				static_cast<sf::Vector2f>(grid->getTiles()[y][x].getWorldPos()));

			if (distance <= epsilon) {
>>>>>>> Joel
				window.draw(*grid->getTiles()[y][x].getSprite());
			}
		}
	}
<<<<<<< HEAD
		
		
	//renderObjects(window);
=======
>>>>>>> Joel
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

float Level::getDistance(sf::Vector2f a, sf::Vector2f b) const
{
	float diffX = b.x - a.x;
	float diffY = b.y - a.y;
	float distance = sqrt((diffX * diffX) + (diffY * diffY));
	return distance;
}

void Level::addTiles(Index current, Index dir, Index childDir, int length, int currentLength)
{
	if (currentLength == length) {
		return;
	}
	tile* t = grid->getTileFromIndex((current.x + dir.x), (current.y + dir.y));
	if (t == nullptr) {
		return;
	}
	drawTiles[nrOfDrawTiles++] = t;

	Index newCurrent = { t->getGridPos().x, t->getGridPos().y};
	
	addTileChild(newCurrent, childDir, 17, 1);

	addTiles(newCurrent, dir, childDir, length, (currentLength + 1));
}

void Level::addTileChild(Index current, Index dir, int length, int currentLength)
{
	if (currentLength == length) {
		return;
	}
	tile* t = grid->getTileFromIndex((current.x + dir.x), (current.y + dir.y));
	if (t == nullptr) {
		return;
	}
	drawTiles[nrOfDrawTiles++] = t;
	Index newCurrent = { t->getGridPos().x, t->getGridPos().y };
	addTileChild(newCurrent, dir, length, (currentLength + 1));
}


void Level::findDrawTiles(Player* player)
{
	nrOfDrawTiles = 0;
	int nrOFTiles = 17;
	tile* midTile = grid->getTileFromWorldPos(static_cast<sf::Vector2i>(player->getPosition()));
	drawTiles[nrOfDrawTiles++] = midTile;
	Index current = { midTile->getGridPos().x, midTile->getGridPos().y};
	
	

	Index dir = { 0, -1 };
	Index childDir = { 1 , 0 };
	addTiles(current, dir, childDir, nrOFTiles, 1); // top

	dir = {1, 0 };
	childDir = { 0, 1 };
	addTiles(current, dir, childDir, nrOFTiles, 1); // right

	dir = { 0, 1 };
	childDir = { -1, 0 };
	addTiles(current, dir, childDir, nrOFTiles, 1); // bot

	dir = {-1, 0 };
	childDir = { 0, -1 };
	addTiles(current, dir, childDir, nrOFTiles, 1); // left;

}

void Level::experimentalDrawLevel(sf::RenderWindow& window) const
{
	for (int i = 0; i < nrOfDrawTiles; ++i) {
		window.draw(*drawTiles[i]->getSprite());
	}
}