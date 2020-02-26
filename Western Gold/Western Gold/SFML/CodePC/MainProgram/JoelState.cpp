#include "JoelState.h"

//debug
#include <iostream>
#include <vector>

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	level = new Level(rm, rm->getLevel_Test());

	enemy = new Enemy(getRm()->getCharacter(), getRm(), 1, level->getGrid());
	enemy->setPosition(48.f, 48.f);
	
	sf::Vector2i* patrollPos = new sf::Vector2i[2];
	patrollPos[0] = { 48,48 };
	patrollPos[1] = {240, 272};
	enemy->engagePatrolState(patrollPos, static_cast<size_t>(2));
	canStart = false;
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
		if (event.mouseButton.button == sf::Mouse::Button::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(*getRm()->getWindow());
			enemy->getPathfinding()->findPath(static_cast<sf::Vector2i>(enemy->getPosition()), mousePos);
		}
		else if (event.mouseButton.button == sf::Mouse::Button::Right) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(*getRm()->getWindow());
			sf::Vector2i pos = level->getGrid()->getTileFromWorldPos(mousePos)->getWorldPos();
			std::cout << pos.x << "." << pos.y << std::endl;
		}
	}

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Space) {
			canStart = true;
		}
	}

	return state;
}

GameState* JoelState::update(DeltaTime time)
{
	GameState* state = this;
	if (canStart) {
		enemy->update(time);
	}
	

	return state;
}

void JoelState::render(sf::RenderWindow& window) const
{
	level->drawLevel(window);
	window.draw(*enemy);
}