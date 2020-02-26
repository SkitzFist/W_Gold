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
