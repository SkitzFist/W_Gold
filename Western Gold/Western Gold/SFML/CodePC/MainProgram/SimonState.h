#pragma once
#include "GameState.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Line.h"
#include "Bullet.h"
#include "Level.h"
#include "Gold.h"

class SimonState : public GameState
{
public:
	SimonState(ResourceManager* rm);
	~SimonState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow& window) const override;
	
private:
	//objects
	Enemy** enemytest;
	Player *p;
	tile** testT;
	Gold** gold;
	Bullet bull;
	//nr of objects
	int nrOfTiles;
	int nrOfEnemies;
	int nrOfGold;

	Level lvl;
	Collision collision;
};

