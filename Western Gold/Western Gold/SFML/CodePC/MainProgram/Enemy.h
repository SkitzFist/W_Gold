#pragma once
#include "Entity.h"
#include "EnemyState.h"

class Enemy :
	public Entity
{
public:
	Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays);
	~Enemy();
	// Inherited via Entity
	virtual void update(DeltaTime delta) override;

private:
	EnemyState* currentState = nullptr;
};

