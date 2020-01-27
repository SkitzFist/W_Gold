#pragma once
#include "GameState.h"

class JoelState : public GameState
{
public:
	JoelState(ResourceManager* rm);
	~JoelState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(sf::Time delta) override;
	virtual void render(sf::RenderWindow& window) const override;
};

