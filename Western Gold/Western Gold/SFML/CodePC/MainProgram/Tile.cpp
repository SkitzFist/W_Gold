#include "tile.h"

tile::tile()
{
	sprite = nullptr;
	worldPos = { 0.f,0.f };
	isWalkable = false;
	eCost = NULL;
	sCost = NULL;
}

tile::tile(sf::Vector2f worldPos, bool isWalkable)
{
	this->worldPos = worldPos;
	this->isWalkable = isWalkable;
	sprite = nullptr;
	eCost = NULL;
	sCost = NULL;
}

tile::~tile()
{
	delete sprite;
}

sf::Vector2f tile::getWorldPos() const
{
	return worldPos;
}

void tile::setWorldPos(sf::Vector2f pos)
{
	this->worldPos = pos;
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
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	centerOrigin();
}

int tile::getTCost()
{
	return sCost + eCost;
}

void tile::centerOrigin()
{
	sprite->setOrigin(
		sprite->getGlobalBounds().width / 2.f,
		sprite->getGlobalBounds().height / 2.f
	);
}
