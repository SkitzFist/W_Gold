#include "JoelState.h"

//debug
#include <iostream>
#include <vector>

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
		
		/*sf::Vector2i mousePos = sf::Mouse::getPosition(*getRm()->getWindow());
		tile* t = level->getGrid()->getTileFromWorldPos(mousePos);
		if (t != nullptr) {
			t->setSprite(getRm()->getTile_Ok());
		}*/

		std::vector<tile*> tiles = level->getTilesOnScreen();
		std::cout << tiles.size();

		timer = -500;
	}

	return getGameState();
}

void JoelState::render(sf::RenderWindow& window) const
{
	level->drawLevel(window);

}
