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
	int getSCost() const;
	void setSCost(int value);
	int getECost() const;
	void setECost(int value);
	//Ray* getRay();
	bool getWannaDraw() const;
	void setWannaDraw(bool value);


private:
	sf::Vector2i worldPos;
	bool isWalkable;
	sf::Sprite* sprite;

	bool wannaDraw;
	//Ray* ray;
	
	int sCost;
	int eCost;

private:
	void centerOrigin();
};

