#include "Entity.h"
#include "Enemy.h"
#include <iostream>
Entity::Entity(sf::Texture *tex, ResourceManager *rm, int nrOfRays):
	GameObject(tex, rm)
{
	//Joel
	this->rm = rm;
	//joel

	this->Dead = false;
	this->raycast = new Ray * [nrOfRays];
	for(int i = 0; i < nrOfRays; i++){
		this->raycast[i] = new Ray((float)i);
		//for enemies 
		if (i > 1) {
			float k = static_cast<float>(i) - 22.5f;
			this->raycast[i]->setRotationOffset(k*1.3, this);
		}
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
	delete ShootRay;
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
	if (!isDead()) {
		for (int i = 0; i < nrOfRays; i++) {
			raycast[i]->updateRay(this);
		}
		ShootRay->updateRay(this);
	}
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	if (!isDead()) {
		GameObject::draw(target, states);
		for (int i = 0; i < nrOfRays; i++) {
			target.draw(*raycast[i]);
		}
	}
}

ResourceManager* Entity::getRm() const
{
	return rm;
}
