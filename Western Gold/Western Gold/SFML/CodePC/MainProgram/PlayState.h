#pragma once
#include "GameState.h"
class PlayState :
	public GameState
{
public:
	PlayState(ResourceManager* rm);
	virtual ~PlayState();

	// Inherited via GameState
	virtual GameState * handleEvent(const sf::Event & event) override;
	virtual GameState * update(sf::Time delta) override;
	virtual void render(sf::RenderWindow& window) const override;


	//debug
	void setupText();
	sf::Text text;
};

