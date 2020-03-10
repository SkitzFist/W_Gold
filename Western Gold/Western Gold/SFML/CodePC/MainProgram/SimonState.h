#pragma once
#include "GameState.h"
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
#include "Line.h"
#include "Bullet.h"
#include "Level.h"
#include "Gold.h"
#include "UI.h"

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
	//camera
	sf::View camera;

	UI ui;

	//objects
	Enemy** enemytest;
	Player *p;
	tile** notWalkableT;
	tile** WalkableT;
	Gold** gold;
	Bullet bull;
	//nr of objects
	int nrOfWalkableTiles;
	int nrOfNonWalkableTiles;
	int nrOfEnemies;
	int nrOfGold;

	Level lvl;
	Collision collision;
};

