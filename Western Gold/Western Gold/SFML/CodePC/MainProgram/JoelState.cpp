#include "JoelState.h"
//debug
#include <iostream>
#include <vector>
#include "PatrollPoints.h"

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	level = new Level(rm, rm->getLevel_01());

	int nrOfTiles = (level->getGrid()->getGridSize().x * level->getGrid()->getGridSize().y);
	player = new Player(rm->getCharacter(), rm, nrOfTiles, 1, 0);
	
	enemy = new Enemy(getRm(), 1, level->getGrid(), player);
	enemy->setPosition(48.f, 48.f);
	
	enemies = new Enemy*[1];
	enemies[0] = enemy;

	canStart = false;
}

JoelState::~JoelState()
{
	delete enemy;
	delete player;
	delete level;
}

GameState* JoelState::handleEvent(const sf::Event& event)
{
	GameState* state = this;

	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Button::Right) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(*getRm()->getWindow());
			sf::Vector2i pos = level->getGrid()->getTileFromWorldPos(mousePos)->getWorldPos();
			std::cout << pos.x << "." << pos.y << std::endl;
		}
	}

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Space) {
			PatrollPoints* patroll = new PatrollPoints(4);
			patroll->add(sf::Vector2i(48,48));
			patroll->add(sf::Vector2i(816,48));
			patroll->add(sf::Vector2i(816, 144));
			patroll->add(sf::Vector2i(48,144));
			enemy->setPatrollPoints(patroll);
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
	window.draw(*player);
}