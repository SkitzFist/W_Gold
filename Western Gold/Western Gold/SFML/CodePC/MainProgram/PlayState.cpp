#include "PlayState.h"



PlayState::PlayState(ResourceManager* rm) :
	GameState(rm)
{
	//config

	//setup
	level = new Level(rm, rm->getLevel_01());
	player = new Player(rm->getCharacter(), rm,
		level->getGrid()->getGridSize().x * level->getGrid()->getGridSize().y,
		18, 0);
	level->placeEnemies(player, enemyHandler);
	//debug

}


PlayState::~PlayState()
{
	delete player;
	delete level;
}

GameState * PlayState::handleEvent(const sf::Event & event)
{
	GameState* state = this;

	return state;
}

GameState * PlayState::update(DeltaTime delta)
{
	GameState* state = this;

	//enemyHandler.update(delta);

	return state;
}

void PlayState::render(sf::RenderWindow&  window) const
{
	level->drawLevel(window);
	//for (int i = 0; i < enemyHandler.getNrOf(); ++i) {
	//	window.draw(*enemyHandler.getEnemies()[i]);
	//}

	//debug
}
