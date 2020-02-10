#include "JoelState.h"

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	level = new Level(rm, rm->getLevel_Test());

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

GameState* JoelState::update(DeltaTime time)
{
	setGameState(this);


	return getGameState();
}

void JoelState::render(sf::RenderWindow& window) const
{
	level->drawLevel(window);
}
