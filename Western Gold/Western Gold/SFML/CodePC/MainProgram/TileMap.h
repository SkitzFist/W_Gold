#pragma once
#include "Tile.h"

class TileMap : public sf::Drawable {
private:
	int nrOfCols;
	int nrOfRows;
	Tile*** tiles;
	void setUpTiles(std::string TileSheet);
	int widthPerTile;
	int heightPerTile;
	sf::Texture *texture;
	
	
public:
	TileMap(int** mapArr, int nrOfCols, int nrOfRows, std::string TileSheet = "../../bin/Images/dragon.jpg", int widthPerTile = 0, int heightPerTile = 0);
	virtual ~TileMap();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};