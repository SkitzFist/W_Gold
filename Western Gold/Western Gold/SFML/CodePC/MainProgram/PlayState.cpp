#include "PlayState.h"



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

GameState * PlayState::update(DeltaTime delta)
{
	setGameState(this);

	text.setString(std::to_string(delta.dt()));

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
