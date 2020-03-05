#pragma once
#include "Entity.h"
#include "EnmState.h"
#include "Pathfinding.h"
#include "Grid.h"

class Enemy :
	public Entity
{
public:
	Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays, Grid* grid);
	~Enemy();

	// Inherited via Entity
	virtual void update(DeltaTime delta) override;
	virtual bool shoot() override;

	Pathfinding* getPathfinding() const;
	void engagePatrolState(sf::Vector2i points[], size_t length);
	Grid* getGrid() const;

	void setDir(sf::Vector2f dir);
	bool isShooting();
	bool seePlayer(bool col, DeltaTime dt);
private:
	//shooting
	float timeToSeePlayer;
	float timeToShootPlayerSee;
	float timeToNextShoot;
	float timeBeetweenShoots;
	bool shooting;

	EnmState* currentState;
	Pathfinding* pathfinding;
	sf::Vector2f dir;

	Grid* grid;

	sf::Vector2i* patrollPoints;
	size_t patrollPointsLength;
};

