#include "PlayState.h"



PlayState::PlayState(ResourceManager* rm):
	GameState(rm),
	level(rm, rm->getLevel_01())
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
	GameState* state = this;

	return state;
}

GameState * PlayState::update(DeltaTime delta)
{
	GameState* state = this;

	return state;
}

void PlayState::render(sf::RenderWindow&  window) const
{
	level.drawLevel(window);
	for (int i = 0; i < enemyHandler.getNrOf(); ++i) {
		window.draw(*enemyHandler.getEnemies()[i]);
	}

	//debug
}
