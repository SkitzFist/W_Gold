#include "tile.h"

tile::tile()
{
	sprite = nullptr;
	worldPos = {0,0};
	isWalkable = false;
	eCost = NULL;
	sCost = NULL;
	sprite = new sf::Sprite();
	ray = new Ray(NULL);
	wannaDraw = true;
	
}

tile::tile(sf::Vector2i worldPos, bool isWalkable)
{
	this->worldPos = worldPos;
	this->isWalkable = isWalkable;
	sprite = nullptr;
	eCost = NULL;
	sCost = NULL;
	sprite = new sf::Sprite();
	ray = nullptr;
	wannaDraw = true;
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

Ray* tile::getRay()
{
	return nullptr;
}

bool tile::getWannaDraw() const
{
	return wannaDraw;
}

void tile::setWannaDraw(bool value)
{
	wannaDraw = value;
}

void tile::centerOrigin()
{
	sprite->setOrigin(
		sprite->getGlobalBounds().width / 2.f,
		sprite->getGlobalBounds().height / 2.f
	);
}