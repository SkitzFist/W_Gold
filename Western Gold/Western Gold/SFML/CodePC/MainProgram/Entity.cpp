#include "Entity.h"

Entity::Entity(sf::Texture *tex, ResourceManager *rm, int nrOfRays):
	GameObject(tex, rm)
{
	this->Dead = false;
	this->raycast = new Ray * [nrOfRays];
	for(int i = 0; i < nrOfRays; i++){
		this->raycast[i] = new Ray((float)i);
	}
	this->ShootRay = new Ray(this->getRotation());
	this->nrOfRays = nrOfRays;
	
}

Entity::~Entity()
{
	for (int i = 0; i < nrOfRays; i++) {
		delete raycast[i];
	}
	delete[] raycast;
}

Ray** Entity::getRays()
{
	return this->raycast;
}

Ray* Entity::getShootRay()
{
	return this->ShootRay;
}

int Entity::getNrOfRays() const
{
	return this->nrOfRays;
}


void Entity::takeDamage()
{
	this->Dead = true;
}

bool Entity::isDead() const
{
	return this->Dead;
}

void Entity::update(DeltaTime& time)
{
	for (int i = 0; i < nrOfRays; i++) {
		raycast[i]->updateRay(this);
	}
	ShootRay->updateRay(this);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < nrOfRays; i++) {
		target.draw(*raycast[i]);
	}
	if (!isDead()) {
		GameObject::draw(target, states);
	}
}
