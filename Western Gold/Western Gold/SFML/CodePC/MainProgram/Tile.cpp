#include "tile.h"

//debug
#include <iostream>

tile::tile()
{
	sprite = nullptr;
	worldPos = {0,0};
	isWalkable = false;
	eCost = NULL;
	sCost = NULL;
	sprite = new sf::Sprite();
	parent = nullptr;
	wannaDraw = true;
	gridPos = { NULL, NULL };
}

tile::tile(sf::Vector2i worldPos, bool isWalkable, sf::Vector2i gridPos, sf::Texture* texture)
{
	this->worldPos = worldPos;
	this->isWalkable = isWalkable;
	eCost = NULL;
	sCost = NULL;
	sprite = new sf::Sprite();
	setSprite(texture);
	setWorldPos(static_cast<sf::Vector2f>(worldPos));

	wannaDraw = true;
	this->gridPos = gridPos;
}

tile::~tile()
{
	delete sprite;
}

sf::Vector2i tile::getWorldPos() const
{
	return worldPos;
}

void tile::setWorldPos(sf::Vector2f pos)
{
	this->worldPos = static_cast<sf::Vector2i>(pos);
	sprite->setPosition(pos);
}

bool tile::getIsWalkable() const
{
	return isWalkable;
}

void tile::setIsWalkable(bool value)
{
	this->isWalkable = value;
}

sf::Sprite* tile::getSprite() const
{
	return sprite;
}

void tile::setSprite(sf::Texture* texture)
{
	sprite->setTexture(*texture);
	centerOrigin();
}

void tile::setGridPos(sf::Vector2i gridPos)
{
	this->gridPos = gridPos;
}

int tile::getTCost()
{
	return sCost + eCost;
}

int tile::getSCost() const
{
	return sCost;
}

void tile::setSCost(int value)
{
	sCost = value;
}

int tile::getECost() const
{
	return eCost;
}

void tile::setECost(int value)
{
	eCost = value;
}

bool tile::getWannaDraw() const
{
	return wannaDraw;
}

void tile::setWannaDraw(bool value)
{
	wannaDraw = value;
}

tile* tile::getParent() const
{
	return parent;
}

void tile::setParent(tile* parent)
{
	this->parent = parent;
}

sf::Vector2i tile::getGridPos() const
{
	return gridPos;
}

void tile::centerOrigin()
{
	sprite->setOrigin(
		sprite->getGlobalBounds().width / 2.f,
		sprite->getGlobalBounds().height / 2.f
	);
}