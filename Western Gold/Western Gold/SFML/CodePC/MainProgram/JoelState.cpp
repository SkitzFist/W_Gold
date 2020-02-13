#include "JoelState.h"

//debug
#include <iostream>

JoelState::JoelState(ResourceManager* rm):
	GameState(rm)
{
	level = new Level(rm, rm->getLevel_Test());
}

JoelState::~JoelState()
{
	delete level;
}

GameState* JoelState::handleEvent(const sf::Event& event)
{
	setGameState(this);


	return getGameState();
}

GameState* JoelState::update(DeltaTime time)
{
	setGameState(this);

	static double timer;
	timer += time.dt();
	
	if (timer > 2.0) {
		
		
		

		timer = 0;
	}

	return getGameState();
}

void JoelState::render(sf::RenderWindow& window) const
{
	level->drawLevel(window);

}
