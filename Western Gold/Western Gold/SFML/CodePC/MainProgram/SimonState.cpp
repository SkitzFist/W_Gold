#include "SimonState.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm)
{
	p = new Player(rm->gettex(), rm);
	testT = new tile(sf::Vector2f(200, 200), true);
	collision.setUpCollision(p, testT);

	setGameState(this);
	testT->setSprite(rm->gettex());
	testT->setWorldPos(sf::Vector2f(200, 200));
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

	p->update(delta);
	collision.update();

	return getGameState();
}

void SimonState::render(sf::RenderWindow& window) const
{
	//window.draw(this->Test);
	window.draw(*this->p);
	window.draw(*this->testT->getSprite());
}
