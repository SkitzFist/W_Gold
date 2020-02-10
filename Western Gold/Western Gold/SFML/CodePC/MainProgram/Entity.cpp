#include "Entity.h"

Entity::Entity(sf::Texture *tex, ResourceManager *rm):
	GameObject(tex, rm)
{
	this->Dead = false;
}


void Entity::takeDamage()
{
	this->Dead = true;
}

bool Entity::isDead() const
{
	return this->Dead;
}
