#include "SimonState.h"
#include <iostream>
#include "Line.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	bull(rm)
	
{
	nrOfTiles = 8;
	
	p = new Player(rm->getCharacter(), rm);
	


	setGameState(this);

	testT = new tile * [nrOfTiles];
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i] = new tile(sf::Vector2i(200, 200), true);
		testT[i]->setSprite(rm->getCharacter());
		testT[i]->setWorldPos(sf::Vector2f(100 * ((float)i + 1), 200));
	}
	collision.setUpCollision(p, testT, nrOfTiles);
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
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i]->getRay()->updateRay(p, testT[i]);
	}
	

	return getGameState();
}

void SimonState::render(sf::RenderWindow& window) const
{
	window.draw(*this->p);
	for (int i = 0; i < nrOfTiles; i++) {
		window.draw(*this->testT[i]->getSprite());
		window.draw(*this->testT[i]->getRay());
	}
	
	window.draw(this->bull);
	
}
