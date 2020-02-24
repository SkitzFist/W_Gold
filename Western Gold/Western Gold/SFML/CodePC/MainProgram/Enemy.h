#pragma once
#include "Entity.h"
#include "EnemyState.h"
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
private:
	

//debug
public:
	Pathfinding* getPathfinding() const;
private:
	Pathfinding* pathfinding;
	tile* nextTile;
	sf::Vector2f getDir();
	bool isAtTile();
	
};

