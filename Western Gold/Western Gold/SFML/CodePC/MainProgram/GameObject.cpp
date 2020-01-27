#include "GameObject.h"

const float PI = 3.14159f;

GameObject::GameObject(sf::Texture* texture)
{
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	spriteColumns = NULL;
	spriteRows = NULL;
}

GameObject::GameObject(sf::Texture* texture, int spriteColumns, int spriteRows)
{
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	this->spriteColumns = spriteColumns;
	this->spriteRows = spriteRows;
}

GameObject::~GameObject()
{
	delete sprite;
}

void GameObject::setPosition(sf::Vector2f pos)
{
	sprite->setPosition(pos);
}

void GameObject::setPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

sf::Vector2f GameObject::getPosition() const
{
	return sprite->getPosition();
}

sf::FloatRect GameObject::getBounds() const
{
	return sprite->getGlobalBounds();
}

void GameObject::rotateSprite(float angle)
{
	sprite->setRotation((angle * 180) / PI + 90);
}

void GameObject::setSpriteScale(float scale)
{
	sprite->setScale(scale, scale);
}

void GameObject::centerOrigin()
{
	float centerX = 0.f;
	float centerY = 0.f;

	if (spriteColumns != NULL && spriteRows != NULL) {
		centerX = sprite->getGlobalBounds().width / (spriteColumns * 2.f);
		centerY = sprite->getGlobalBounds().height / (spriteRows * 2.f);
	}
	else {
		centerX = sprite->getGlobalBounds().width / 2.f;
		centerY = sprite->getGlobalBounds().height / 2.f;
	}
	sprite->setOrigin(centerX, centerY);
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*sprite);
}

void GameObject::moveSprite(sf::Vector2f dir, float speed)
{
	sprite->move(dir * speed);
}

void GameObject::moveSprite(float velX, float velY)
{
	sprite->move(velX, velY);
}