#pragma once
#include "GameObject.h"
#include "Ray.h"

class Entity : public GameObject{
private:
	bool Dead;
	Ray **raycast;
	int nrOfRays;
public:
	Entity(sf::Texture *tex, ResourceManager *rm , int nrOfRays);
	void takeDamage();
	bool isDead()const;
	void update(DeltaTime &time);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};