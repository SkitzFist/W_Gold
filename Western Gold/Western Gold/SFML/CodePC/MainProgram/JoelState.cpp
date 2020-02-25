#include "JoelState.h"

//debug
#include <iostream>
#include <vector>
#include "PlayState.h"

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	level = new Level(rm, rm->getLevel_Test());

	enemy = new Enemy(getRm()->getCharacter(), getRm(), 1, level->getGrid());
	enemy->setPosition(48.f, 48.f);

}

JoelState::~JoelState()
{
	delete enemy;
	delete level;
}

GameState* JoelState::handleEvent(const sf::Event& event)
{
	GameState* state = this;

	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(*getRm()->getWindow());
		enemy->getPathfinding()->findPath(static_cast<sf::Vector2i>(enemy->getPosition()), mousePos);
	}

	return state;
}

GameState* JoelState::update(DeltaTime time)
{
	GameState* state = this;
	
	enemy->update(time);

	return state;
}

void JoelState::render(sf::RenderWindow& window) const
{
	level->drawLevel(window);
	window.draw(*enemy);
}