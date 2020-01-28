#pragma once
#include <SFML/Graphics.hpp>

/*Notes:
	beh�ver raycast
	enemy beh�ver raycast ocks�*/
class Node
{
public:
	Node();
	Node(sf::Vector2f worldPos, bool isWalkable);
	~Node();
	sf::Vector2f getWorldPos() const;
	bool getIsWalkable() const;
	sf::Sprite getSprite() const;
	void setSprite(sf::Texture* texture);
	int getSCost() const;
private:
	sf::Vector2f worldPos;
	bool isWalkable;
	sf::Sprite sprite;

	int sCost;
	int eCost;
};

