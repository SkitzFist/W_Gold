#include "Node.h"

Node::Node()
{
	worldPos = { 0.f,0.f };
	isWalkable = true;
	eCost = NULL;
	sCost = NULL;
}

Node::Node(sf::Vector2f worldPos, bool isWalkable)
{
	this->worldPos = worldPos;
	this->isWalkable = isWalkable;
	eCost = NULL;
	sCost = NULL;
}

Node::~Node()
{
}

sf::Vector2f Node::getWorldPos() const
{
	return worldPos;
}

void Node::setWorldPos(sf::Vector2f worldPos)
{
	this->worldPos = worldPos;
	sprite.setPosition(worldPos);
}

bool Node::getIsWalkable() const
{
	return isWalkable;
}

void Node::setIsWalkable(bool value)
{
	isWalkable = value;
}

sf::Sprite Node::getSprite() const
{
	return sprite;
}

void Node::setSprite(sf::Texture* texture)
{
	sprite.setTexture(*texture);
}

int Node::getTCost() const
{
	return sCost;
}
