#include "MainMenuState.h"
#include "PlayState.h"


MainMenuState::MainMenuState()
{
}


MainMenuState::~MainMenuState()
{
}

GameState * MainMenuState::handleEvent(const sf::Event & event)
{
	setGameState(this);

	return getGameState();
}

GameState * MainMenuState::update(DeltaTime delta)
{
	setGameState(this);


	return getGameState();
}

void MainMenuState::render(sf::RenderWindow & window) const
{
}
