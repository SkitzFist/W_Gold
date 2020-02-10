#pragma once
#include "Entity.h"

class Player :public Entity{
private:
	void move(DeltaTime time);
	void shoot();
	void rotation();
	float speed;
public:
	Player(sf::Texture* tex, ResourceManager* rm);
	//virtual~Player();
	void update(DeltaTime time);
};