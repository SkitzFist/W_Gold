#include "LoadState.h"
#include "MenuState.h"
//debug
#include <iostream>
LoadState::LoadState(ResourceManager* rm) :
	GameState(rm)
{
	//config
	sf::Vector2f loadPos = {
		static_cast<float>(rm->getWindowWidth() / 2.f),
		static_cast<float>(rm->getWindowHeight() / 2.f)
	};
	//setup
	loadStatus = 0;
	loadText.setFont(*rm->getBasicFont());
	loadText.setCharacterSize(54);
	loadText.setPosition(loadPos);
	loadText.setString("Loading " + std::to_string(loadStatus) + "%");

	tileThread = std::thread(&LoadState::loadTilesAndLevel, this);
	spriteThread = std::thread(&LoadState::loadSprites, this);
	soundThread = std::thread(&LoadState::loadSound, this);
}

LoadState::~LoadState()
{
	tileThread.join();
	spriteThread.join();
	soundThread.join();
}

GameState* LoadState::handleEvent(const sf::Event& event)
{
	GameState* state = this;


	return state;
}

GameState* LoadState::update(DeltaTime delta)
{
	GameState* state = this;

	loadText.setString("Loading " + std::to_string(loadStatus) + "%");

	if (loadStatus > 98) {
		state = new MenuState(getRm());
		delete this;
	}
	return state;
}

void LoadState::render(sf::RenderWindow& window) const
{
	window.draw(loadText);
}

void LoadState::loadTilesAndLevel()
{
	getRm()->loadTilesAndLevels();
	this->loadStatus += 33;
	std::cout << "Tiles finished" << std::endl;
}

void LoadState::loadSprites()
{
	getRm()->loadSprites();
	loadStatus += 33;
	std::cout << "Sprites finished" << std::endl;
}

void LoadState::loadSound()
{
	getRm()->loadSounds();
	loadStatus += 33;
	std::cout << "Sounds finished" << std::endl;
}

