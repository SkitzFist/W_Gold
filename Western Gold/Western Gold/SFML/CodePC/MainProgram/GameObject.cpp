#include "GameObject.h"

const float PI = 3.14159f;

GameObject::GameObject(sf::Texture* texture, ResourceManager* rm, int spriteColumns, int spriteRows)
{
	this->rm = rm;
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	centerOrigin();
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

float GameObject::getLeft() const
{
	return sprite->getGlobalBounds().left;
}

float GameObject::getRight() const
{
	return sprite->getGlobalBounds().left + sprite->getGlobalBounds().width;
}

float GameObject::getBot() const
{
	return sprite->getGlobalBounds().top + sprite->getGlobalBounds().height;
}

float GameObject::getTop() const
{
	return sprite->getGlobalBounds().top;
}

float GameObject::getWidth()
{
	return sprite->getGlobalBounds().width;
}

float GameObject::getHeight()
{
	return sprite->getGlobalBounds().height;
}

float GameObject::getRotation()
{
	return sprite->getRotation();
}

void GameObject::setRotatioSprite(float angle)
{
	sprite->setRotation(angle);
}

void GameObject::rotateSprite(float angle)
{
	sprite->setRotation((angle * 180) / PI + 90);
}

void GameObject::addRotationSprite(float angle)
{
	sprite->setRotation(sprite->getRotation()+ angle);
}

void GameObject::setSpriteScale(float scale)
{
	sprite->setScale(scale, scale);
}

void GameObject::setSpriteScalePx(float sizeX, float sizeY)
{
	sizeX = sizeX / sprite->getGlobalBounds().width;
	sizeY = sizeY / sprite->getGlobalBounds().height;
	sprite->setScale(sizeX, sizeY);
}

sf::Vector2f GameObject::getCenterOfSprite() const
{
	return sf::Vector2f(sprite->getGlobalBounds().width / 2.f, sprite->getGlobalBounds().height / 2.f);
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

ResourceManager* GameObject::getRm()
{
	return this->rm;
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

void GameObject::setanimation(float timeBetween, int nrofCol, int nrOfRows, int whatRow)
{
	animator.setAnimation(this->sprite, timeBetween, nrofCol, nrOfRows, whatRow);
}
