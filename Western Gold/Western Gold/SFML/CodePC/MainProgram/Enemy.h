#pragma once
#include "Entity.h"
#include "EnmState.h"
#include "Pathfinding.h"
#include "Grid.h"

class Collision;
class Enemy :
	public Entity
{
public:
	Enemy(sf::Texture* tex, ResourceManager* rm, int nrOfRays, Grid* grid, Player* player);
	~Enemy();

	// Inherited via Entity
	virtual void update(DeltaTime delta) override;
	virtual bool shoot() override;

	Pathfinding* getPathfinding() const;
	void engagePatrolState(sf::Vector2i points[], size_t length);
	Grid* getGrid() const;
	
	void setIsPlayerInSight(Collision &col);
	bool getIsPlayerInSight();
	Player* getPlayer();

	sf::Vector2i* getPatrollPoints() const;
	size_t getPatrollPointsLength() const;

	Player* getPlayer() const;
	void setDir(sf::Vector2f dir);
	bool isShooting();

private:
	Player* player;
	bool isPlayerInSight;

	EnmState* currentState;
	Pathfinding* pathfinding;
	sf::Vector2f dir;
	Grid* grid;
	sf::Vector2i* patrollPoints;
	size_t patrollPointsLength;
};

