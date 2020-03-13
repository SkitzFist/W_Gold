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
	player->setPosition(600.f, 600.f);
	level->placeEnemies(player, enemyHandler);
	
	
	//debug
	fpsText = new Text(rm->getBasicFont(), "FPS", sf::Vector2f(30.f, 40.f));
	currentTime = 0.0;
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
	player->update(delta);
	camera.setCenter(player->getPosition());
	enemyHandler.update(delta);

	level->findDrawTiles(player);

	currentTime = delta.dt();
	double fps = 1.0 / (currentTime);
	fpsText->setPosition(player->getPosition());
	fpsText->setText(fps);
	return state;
}

void PlayState::render(sf::RenderWindow&  window) const
{
	
	window.setView(camera);
	//level->drawLevel(window, player);

	level->experimentalDrawLevel(window);

	for (int i = 0; i < enemyHandler.getNrOf(); ++i) {
		window.draw(*enemyHandler.getEnemies()[i]);
	}

	window.draw(*fpsText);
	//debug
}
