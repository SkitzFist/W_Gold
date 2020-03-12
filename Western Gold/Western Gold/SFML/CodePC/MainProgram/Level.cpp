#include "Level.h"
#include <vector>

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
#pragma region Guard_01
	sf::Vector2i points[12];
	points[0] = { 7, 20 };
	points[1] = { 17, 20 };
	points[2] = { 17, 24 };
	points[3] = { 13, 24 };
	points[4] = { 13, 41 };
	points[5] = { 17, 41 };
	points[6] = { 17, 43 };
	points[7] = { 7, 43 };
	points[8] = { 7, 33 };
	points[9] = { 11, 33 };
	points[10] = { 11, 22 };
	points[11] = { 7, 22 };
	engageEnemyPatrollPoints(*points, 12, handler, player);
#pragma endregion
//
//#pragma region Guard_02
//	points = new sf::Vector2i[4];
//	points[0] = { 23, 6 };
//	points[1] = { 23, 58 };
//	points[2] = { 82, 58 };
//	points[3] = { 82, 6 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_03
//	points = new sf::Vector2i[4];
//	points[0] = { 82, 58 };
//	points[1] = { 82, 6 };
//	points[2] = { 23, 6 };
//	points[3] = { 23, 58 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_04
//	points = new sf::Vector2i[4];
//	points[0] = { 40, 16 };
//	points[1] = { 65, 16 };
//	points[2] = { 65, 11 };
//	points[3] = {40, 11 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_05
//	points = new sf::Vector2i[2];
//	points[0] = { 35, 27 };
//	points[1] = { 35, 16 };
//	engageEnemyPatrollPoints(points, 2, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_06
//	points = new sf::Vector2i[4];
//	points[0] = { 47,27 };
//	points[1] = { 47,21 };
//	points[2] = { 39,21 };
//	points[3] = { 39,27 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_07
//	points = new sf::Vector2i[4];
//	points[0] = { 56,25 };
//	points[1] = { 64,25 };
//	points[2] = { 64,31 };
//	points[3] = { 77,25 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_08
//	points = new sf::Vector2i[3];
//	points[0] = { 27,23 };
//	points[1] = { 27,50 };
//	points[2] = { 31,5};
//	engageEnemyPatrollPoints(points, 3, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_09
//	points = new sf::Vector2i[4];
//	points[0] = { 39,33 };
//	points[1] = { 39,40 };
//	points[2] = { 45,40 };
//	points[3] = { 45,33 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_10
//	points = new sf::Vector2i[4];
//	points[0] = { 46,48 };
//	points[1] = { 46,33 };
//	points[2] = { 53,33 };
//	points[3] = { 55,48 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_11
//	points = new sf::Vector2i[4];
//	points[0] = { 58,34 };
//	points[1] = { 58,49 };
//	points[2] = { 69,49 };
//	points[3] = { 69,34 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_12
//	points = new sf::Vector2i[2];
//	points[0] = { 27,53 };
//	points[1] = { 73,53 };
//	engageEnemyPatrollPoints(points, 2, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_13
//	points = new sf::Vector2i[4];
//	points[0] = { 21,46 };
//	points[1] = { 16,67 };
//	points[2] = { 16,69 };
//	points[3] = { 2,69 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_14
//	points = new sf::Vector2i[4];
//	points[0] = { 21,73 };
//	points[1] = { 21,67 };
//	points[2] = { 29,67 };
//	points[3] = { 29,73 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_15
//	points = new sf::Vector2i[4];
//	points[0] = { 21,73 };
//	points[1] = { 21,67 };
//	points[2] = { 29,67 };
//	points[3] = { 29,73 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_16
//	points = new sf::Vector2i[4];
//	points[0] = { 37,67 };
//	points[1] = { 36,67 };
//	points[2] = { 36,73 };
//	points[3] = { 34,73};
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_17
//	points = new sf::Vector2i[4];
//	points[0] = { 44,67 };
//	points[1] = { 42,67 };
//	points[2] = { 42,73 };
//	points[3] = { 44,73 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
//#pragma region Guard_18
//	points = new sf::Vector2i[4];
//	points[0] = { 85,72 };
//	points[1] = { 66,72 };
//	points[2] = { 66,66 };
//	points[3] = { 56,66 };
//	engageEnemyPatrollPoints(points, 4, handler, player);
//	delete[] points;
//#pragma endregion
}

void Level::engageEnemyPatrollPoints(sf::Vector2i& points, int nrOf, EnemyHandler& handler, Player* player)
{
	//sf::Vector2i* patrollPoints = new sf::Vector2i;
	//for (int i = 0; i < nrOf; ++i) {
	//	tile* t = &getGrid()->getTiles()[points.y][points.x];
	//	patrollPoints[i] = t->getWorldPos();
	//}
	//Enemy* newEnemy = new Enemy(rm->getEnemy(), rm, 90, grid, player);
	//newEnemy->setPosition(static_cast<sf::Vector2f>(patrollPoints[0]));
	//newEnemy->setPatrollPoints(patrollPoints, static_cast<size_t>(nrOf));
	//handler.add(newEnemy);

}
