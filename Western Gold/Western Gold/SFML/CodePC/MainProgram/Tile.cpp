#include "tile.h"

tile::tile()
{
	this->ray = new Ray();
	sprite = nullptr;
	worldPos = {0,0};
	isWalkable = false;
	eCost = NULL;
	sCost = NULL;
	sprite = new sf::Sprite();
}

tile::tile(sf::Vector2i worldPos, bool isWalkable)
{
	this->ray = new Ray();
	this->worldPos = worldPos;
	this->isWalkable = isWalkable;
	sprite = nullptr;
	eCost = NULL;
	sCost = NULL;
	sprite = new sf::Sprite();
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

Ray* tile::getRay()
{
	return ray;
}

void tile::centerOrigin()
{
	sprite->setOrigin(
		sprite->getGlobalBounds().width / 2.f,
		sprite->getGlobalBounds().height / 2.f
	);
}
