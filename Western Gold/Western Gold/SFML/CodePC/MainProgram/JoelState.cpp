#include "JoelState.h"
//debug
#include <iostream>
#include <vector>

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	level = new Level(rm, rm->getLevel_Test03());

	int nrOfTiles = (level->getGrid()->getGridSize().x * level->getGrid()->getGridSize().y);
	player = new Player(rm->getCharacter(), rm, nrOfTiles, 1);

	
	enemy = new Enemy(getRm()->getEnemy(), getRm(), 1, level->getGrid(), player);
	enemy->setPosition(48.f, 48.f);
	
	enemies = new Enemy * [1];
	enemies[0] = enemy;


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
		if (event.mouseButton.button == sf::Mouse::Button::Right) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(*getRm()->getWindow());
			sf::Vector2i pos = level->getGrid()->getTileFromWorldPos(mousePos)->getWorldPos();
			std::cout << pos.x << "." << pos.y << std::endl;
		}
	}

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Space) {
			sf::Vector2i* patrollPos = new sf::Vector2i[2];
			patrollPos[0] = { 240,112 };
			patrollPos[1] = { 752, 112 };
			enemy->engagePatrolState(patrollPos, static_cast<size_t>(2));
			canStart = true;
		}
	}

	return state;
}

GameState* JoelState::update(DeltaTime time)
{
	GameState* state = this;

	if (canStart) {
		//enemy->setIsPlayerInSight(*col);
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