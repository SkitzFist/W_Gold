#pragma once
#include "GameObject.h"

class Entity : public GameObject{
private:
	bool Dead;
public:
	Entity(sf::Texture *tex, ResourceManager *rm );
	//virtual~Entity() = 0;
	void takeDamage();
	bool isDead()const;
};