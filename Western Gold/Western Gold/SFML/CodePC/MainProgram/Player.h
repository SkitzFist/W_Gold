#pragma once
#include "Entity.h"

class Player : public Entity{
private:
	void move(DeltaTime time);
	
	void rotation();
	float speed;
	sf::RenderWindow* window;
public:
	bool shoot();
	Player(sf::Texture* tex, ResourceManager* rm);
	virtual~Player();
	void update(DeltaTime time);
};