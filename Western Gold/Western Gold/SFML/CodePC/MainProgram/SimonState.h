#pragma once
#include "GameState.h"
#include "testObj.h"
#include "Player.h"
#include "Collision.h"

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
	tile *testT;

	Collision collision;
};

