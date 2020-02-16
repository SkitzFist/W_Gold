#pragma once
#include "Ray.h"
class tile
{
public:
	tile();
	tile(sf::Vector2i worldPos, bool isWalkable);
	~tile();

	sf::Vector2i getWorldPos() const;
	void setWorldPos(sf::Vector2f pos);
	bool getIsWalkable() const;
	void setIsWalkable(bool value);
	sf::Sprite* getSprite() const;
	void setSprite(sf::Texture* texture);
	int getTCost();

private:
	sf::Vector2i worldPos;
	bool isWalkable;
	sf::Sprite* sprite;
	
	int sCost;
	int eCost;

private:
	void centerOrigin();
};

