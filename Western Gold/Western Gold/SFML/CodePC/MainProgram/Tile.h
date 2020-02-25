#pragma once
#include "Ray.h"
class tile
{
public:
	tile();
	tile(sf::Vector2i worldPos, bool isWalkable, sf::Vector2i gridPos, sf::Texture* texture);
	~tile();

	void setSprite(sf::Texture* texture);
	sf::Sprite* getSprite() const;
	bool getWannaDraw() const;
	void setWannaDraw(bool value);
	Ray* getRay();


	sf::Vector2i getWorldPos() const;
	void setWorldPos(sf::Vector2f pos);
	bool getIsWalkable() const;
	void setIsWalkable(bool value);

	void setGridPos(sf::Vector2i gridPos);
	sf::Vector2i getGridPos() const;

	int getTCost();
	int getSCost() const;
	void setSCost(int value);
	int getECost() const;
	void setECost(int value);


	tile* getParent()const;
	void setParent(tile* parent);

	

private:

	sf::Vector2i worldPos;
	bool isWalkable;
	sf::Sprite* sprite;
	sf::Vector2i gridPos;

	bool wannaDraw;
	Ray* ray;
	
	int sCost;
	int eCost;

	tile* parent;
private:
	void centerOrigin();
};

