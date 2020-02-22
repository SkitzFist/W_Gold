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
	virtual ~Entity();
	Ray *getRays();
	void takeDamage();
	bool isDead()const;
	void update(DeltaTime &time);
	virtual bool shoot() = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};