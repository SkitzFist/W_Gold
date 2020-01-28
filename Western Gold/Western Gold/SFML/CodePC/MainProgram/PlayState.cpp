#include "PlayState.h"
#include <iostream>


PlayState::PlayState(ResourceManager* rm):
	GameState(rm)
{
	//config

	//setup

	//debug
	setupText();
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
	text.setString(std::to_string(time.dt()));

	return getGameState();
}

void PlayState::render(sf::RenderWindow&  window) const
{

	//debug
	window.draw(text);
}

void PlayState::setupText()
{
	text.setFont(*getRm()->getBasicFont());
	sf::Vector2f pos{
		getRm()->getWindowWidth() / 2.f,
		getRm()->getWindowHeight() / 2.f
	};
	text.setPosition(pos);
}
