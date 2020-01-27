#include "SimonState.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm)
{
	setGameState(this);
}

SimonState::~SimonState()
{
}

GameState* SimonState::handleEvent(const sf::Event& event)
{
	setGameState(this);


	return getGameState();
}

GameState* SimonState::update(sf::Time delta)
{
	setGameState(this);


	return getGameState();
}

void SimonState::render(sf::RenderWindow& window) const
{
}
