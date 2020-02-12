#include "Grid.h"
#include "Utils.h"

//debug
#include <iostream>

Grid::Grid(ResourceManager* rm, sf::Image*level)
{
	//Config
	setTileSize(rm);

	//Setup
	worldSize = {level->getSize().x, level->getSize().y};
	tiles = allocateTwoDimensionalArray<tile>(worldSize.x, worldSize.y);
	initGrid(rm,level);
	//Debug
}

Grid::~Grid()
{
	deallocateTwoDimensionalArray(tiles, worldSize.x);
}

tile** Grid::getTiles() const
{
	return tiles;
}

tile* Grid::getTileFromWorldPos(sf::Vector2i pos)
{
	float percentX = (pos.x + worldSize.x / 2.f) / worldSize.x;
	float percentY = (pos.y + worldSize.y / 2.f) / worldSize.y;
	//if not working clamp between 0-1

	int x = static_cast<int>( std::round(worldSize.x - 1) * percentX);
	int y = static_cast<int>(std::round(worldSize.y - 1) * percentY);

	return &tiles[x][y];
}

//debug

void Grid::renderGrid(sf::RenderWindow& window) const
{
	for (unsigned int x = 0; x < worldSize.x; ++x) {
		for (unsigned int y = 0; y < worldSize.y; ++y) {

			window.draw(*tiles[y][x].getSprite());
		}
	}
}

void Grid::initGrid(ResourceManager* rm,sf::Image* level)
{
	sf::Color whiteTile = { 255,255,255 };
	sf::Color blackTile = { 0,0,0 };
	sf::Vector2f pos = {-nodeSize , -nodeSize};
	
	for (unsigned int x = 0; x < worldSize.x; ++x) {
		pos.x += nodeSize;
		pos.y = -nodeSize;
		for (unsigned int y = 0; y < worldSize.y; ++y) {
			pos.y += nodeSize;

			sf::Color pixelInlevel = level->getPixel(x, y);
			if (pixelInlevel == whiteTile) {
				
				tiles[y][x].setSprite(rm->getTile_White());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(true);
			}
			else if (pixelInlevel == blackTile) {
				tiles[y][x].setSprite(rm->getTile_Black());
				tiles[y][x].setWorldPos(pos);
				tiles[y][x].setIsWalkable(true);
			}
		}
	}
}

void Grid::setTileSize(ResourceManager* rm)
{
	sf::Sprite sprite;
	sprite.setTexture(*rm->getTile_White());
	nodeSize = sprite.getGlobalBounds().width;
}
