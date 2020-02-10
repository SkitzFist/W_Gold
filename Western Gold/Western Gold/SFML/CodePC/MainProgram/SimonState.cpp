#include "SimonState.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	Test(rm),
	p(rm->gettex(),rm)
{
	setGameState(this);
}

SimonState::~SimonState()
{
}

GameState* SimonState::handleEvent(const sf::Event& event)
{
	setGameState(this);


	return getGameState();
}

GameState* SimonState::update(DeltaTime delta)
{
	setGameState(this);
	//Test.update(delta);
	p.update(delta);

	return getGameState();
}

void SimonState::render(sf::RenderWindow& window) const
{
	//window.draw(this->Test);
	window.draw(this->p);
}
