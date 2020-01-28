#include "Node.h"

Node::Node()
{
	worldPos = { 0.f,0.f };
	isWalkable = true;
}

Node::Node(sf::Vector2f worldPos, bool isWalkable)
{
	this->worldPos = worldPos;
	this->isWalkable = isWalkable;
}

Node::~Node()
{
}

sf::Vector2f Node::getWorldPos() const
{
	return worldPos;
}

bool Node::getIsWalkable() const
{
	return isWalkable;
}

sf::Sprite Node::getSprite() const
{
	return sprite;
}

void Node::setSprite(sf::Texture* texture)
{
	sprite.setTexture(*texture);
}

int Node::getSCost() const
{
	return sCost;
}
