#include "PlayState.h"
#include <iostream>


PlayState::PlayState(ResourceManager* rm):
	GameState(rm)
{
	//config

	//setup

	//debug
}


PlayState::~PlayState()
{
}

GameState * PlayState::handleEvent(const sf::Event & event)
{
	setGameState(this);

	return getGameState();
}

GameState * PlayState::update(DeltaTime time)
{
	setGameState(this);
	std::cout << time.dt() << std::endl;

	return getGameState();
}

void PlayState::render(sf::RenderWindow&  window) const
{


}


