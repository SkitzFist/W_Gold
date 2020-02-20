#pragma once
#include "GameState.h"
#include "Player.h"
#include "Collision.h"
#include "Line.h"
#include "Bullet.h"

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
	Player *p;
	int nrOfTiles;
	tile** testT;
	Bullet bull;

	Collision collision;
};

