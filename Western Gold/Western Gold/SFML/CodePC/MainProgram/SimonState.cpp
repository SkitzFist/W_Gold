#include "SimonState.h"
#include <iostream>
#include "Line.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	bull(rm)
	
{
	p = new Player(rm->getCharacter(), rm);
	testT = new tile(sf::Vector2i(200, 200), true);
	collision.setUpCollision(p, testT,1);

	setGameState(this);
	testT->setSprite(rm->getCharacter());
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
	bull.update(delta);
	collision.update();
	//testing for throwing;
	if (p->shoot()) {
		bull.throwBullet(delta, *p);
	}
	if (p->getRays()->rayHitTile(testT)) {
		
	}

	return getGameState();
}

void SimonState::render(sf::RenderWindow& window) const
{
	//window.draw(this->Test);
	window.draw(*this->p);
	window.draw(*this->testT->getSprite());
	window.draw(this->bull);
}
