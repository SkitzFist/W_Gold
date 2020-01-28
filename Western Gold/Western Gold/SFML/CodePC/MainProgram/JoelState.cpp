#include "JoelState.h"

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	level = new Level(rm, *rm->getLevel_test());
}

JoelState::~JoelState()
{
	delete level;
}

GameState* JoelState::handleEvent(const sf::Event& event)
{
	setGameState(this);


	return getGameState();
}

GameState* JoelState::update(sf::Time delta)
{
	setGameState(this);


	return getGameState();
}

void JoelState::render(sf::RenderWindow& window) const
{
}
