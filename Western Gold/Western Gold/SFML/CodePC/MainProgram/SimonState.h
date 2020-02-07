#pragma once
#include "GameState.h"
#include "SoundManager.h"
#include "testObj.h"

class SimonState : public GameState
{
public:
	SimonState(ResourceManager* rm);
	~SimonState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime time) override;
	virtual void render(sf::RenderWindow& window) const override;
	test Test;
private:
	sf::Text text;
	void setupText();
};

