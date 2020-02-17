#include "JoelState.h"

//debug
#include <iostream>
#include <vector>
#include "PlayState.h"

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	enemy = new Enemy(getRm()->getCharacter(), getRm(), 1);
}

JoelState::~JoelState()
{
	delete enemy;
}

GameState* JoelState::handleEvent(const sf::Event& event)
{
	setGameState(this);

	if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::Space) {
			
		}
	}

	return getGameState();
}

GameState* JoelState::update(DeltaTime time)
{
	//setGameState(this);
	GameState* state = this;
	
	enemy->update(time);

	return state;
}

void JoelState::render(sf::RenderWindow& window) const
{
	

}
