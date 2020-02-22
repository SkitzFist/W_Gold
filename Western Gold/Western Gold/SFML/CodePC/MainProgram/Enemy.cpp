#include "Enemy.h"
#include "PatrolState.h"

Enemy::Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays):
Entity(tex, rm, nrOfRays)
{
	//currentState = new PatrolState();
}

Enemy::~Enemy()
{
	//delete currentState;
}

bool Enemy::shoot()
{
	return false;
}

void Enemy::update(DeltaTime delta)
{
	//currentState = currentState->update(delta);
}
