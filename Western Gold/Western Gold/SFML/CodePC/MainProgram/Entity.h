#pragma once
#include "GameObject.h"
#include "Ray.h"

class Entity : public GameObject{
private:
	bool Dead;
	Ray **raycast;
	Ray* ShootRay;
	int nrOfRays;
	ResourceManager* rm;
public:
	Entity(sf::Texture *tex, ResourceManager *rm , int nrOfRays);
	virtual ~Entity();

	Ray **getRays();
	Ray* getShootRay();
	int getNrOfRays()const;

	void takeDamage();
	bool isDead()const;
	void update(DeltaTime &time);
	virtual bool shoot() = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//joel
	ResourceManager* getRm() const;
	
};