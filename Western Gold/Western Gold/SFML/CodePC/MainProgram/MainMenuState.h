#pragma once
#include "GameState.h"
class MainMenuState :
	public GameState
{
public:
	MainMenuState();
	~MainMenuState();

	// Inherited via GameState
	virtual GameState * handleEvent(const sf::Event & event) override;
	virtual GameState * update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow & window) const override;
};

