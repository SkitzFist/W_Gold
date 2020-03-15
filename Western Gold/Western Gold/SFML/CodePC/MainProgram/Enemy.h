#pragma once
#include "Entity.h"
#include "EnmState.h"
#include "Pathfinding.h"
#include "PatrollPoints.h"
#include "Grid.h"

class Collision;
class Enemy :
	public Entity
{
public:
	Enemy(ResourceManager* rm, int nrOfRays, Grid* grid, Player* player);
	~Enemy();

	// Inherited via Entity
	virtual void update(DeltaTime delta) override;
	virtual bool shoot() override;

	Pathfinding* getPathfinding() const;
	void setPatrollPoints(PatrollPoints* patroll);
	Grid* getGrid() const;
	
	bool getIsPlayerInSight();

	PatrollPoints* getPatroll();

	Player* getPlayer() const;
	void setDir(sf::Vector2f dir);
	sf::Vector2f getDir() const;
	bool isShooting();
	int getSeeDistance()const;
	void changePlayerInSight(bool Sight);
	//debug
	void setCollision(Collision& collision);
	Collision* getCollision();
private:
	Player* player;
	bool isPlayerInSight;
	Collision* collision;
	int seeDistance;
	EnmState* currentState;
	Pathfinding* pathfinding;
	sf::Vector2f dir;
	Grid* grid;
	PatrollPoints* patroll;
};

