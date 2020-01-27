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
	state = this;

	return state;
}

GameState * PlayState::update(sf::Time delta)
{
	state = this;

	text.setString(std::to_string(delta.asSeconds()));

	return state;
}

void PlayState::render(sf::RenderWindow&  window) const
{

	//debug
	window.draw(text);
}

void PlayState::setupText()
{
	text.setFont(*rm->getBasicFont());
	sf::Vector2f pos{
		rm->getWindowWidth() / 2.f,
		rm->getWindowHeight() / 2.f
	};
	text.setPosition(pos);
}
