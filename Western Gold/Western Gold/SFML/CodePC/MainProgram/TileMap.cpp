#include "TileMap.h"

void TileMap::setUpTiles(std::string TileSheet)
{
	for (int row = 0; row < nrOfRows; row++) {
		for (int col = 0; col < nrOfCols; col++) {
			this->tiles[row][col] = new Tile(texture, (float)col * this->widthPerTile, (float)row * this->heightPerTile);
			//how big each Tile should be
			this->tiles[row][col]->setSpriteScale(0.3);
		}
	}
	
}

TileMap::TileMap(int** mapArr, int nrOfCols, int nrOfRows, std::string TileSheet, int widthPerTile, int heightPerTile)
{
	
	texture = new sf::Texture;
	texture->loadFromFile(TileSheet);
	this->widthPerTile = widthPerTile;
	this->heightPerTile = heightPerTile;
	this->nrOfCols = nrOfCols;
	this->nrOfRows = nrOfRows;
	this->tiles = new Tile** [this->nrOfRows];
	for (int i = 0; i < this->nrOfRows; i++) {
		this->tiles[i] = new Tile*[this->nrOfCols];
	}
	setUpTiles(TileSheet);
}

TileMap::~TileMap()
{
	for (int col = 0; col < nrOfCols; col++) {
		for (int row = 0; row < nrOfRows; row++) {
			delete tiles[col][row];
		}
		delete[] tiles[col];
	}
	delete[] tiles;
	delete texture;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int row = 0; row < nrOfRows; row++) {
		for (int col = 0; col < nrOfCols; col++) {
			target.draw(*this->tiles[row][col]);
		}
	}
}
