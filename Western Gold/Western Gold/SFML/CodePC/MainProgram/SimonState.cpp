#include "SimonState.h"
#include <iostream>
#include "Line.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	bull(rm)
	
{
	nrOfTiles = 8;
	
	p = new Player(rm->getCharacter(), rm, nrOfTiles, testT);
	


	setGameState(this);

	testT = new tile * [nrOfTiles];
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i] = new tile(sf::Vector2i(200, 200), true);
		testT[i]->setSprite(rm->getCharacter());
		testT[i]->setWorldPos(sf::Vector2f(100 * ((float)i + 1), 200.0f+(float)i*(5.0f)*(sin(i) + 1) * 5));
	}
	collision.setUpCollision(p, testT, nrOfTiles);
}

SimonState::~SimonState()
{
	for (int i = 0; i < nrOfTiles; i++) {
		delete testT[i];
	}
	delete[] testT;
	delete p;
	
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
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i]->setWannaDraw(true);
	}

	bull.update(delta);
	collision.update();
	//testing for throwing;
	if (p->tossBullet()) {
		bool gotaBullet = false;
		for (int i = 0; i < 6 && !gotaBullet; i++) {
			if (bull.getBulletState() == 0) {
				bull.throwBullet(delta, *p);
				gotaBullet = true;
			}
		}
	}
	if (p->shoot()) {
		//check what he shot
		std::cout << "shoot" << std::endl;
	}
	for (int i = 0; i < nrOfTiles; i++) {
		p->getRay(i)->updateRay(p, testT[i]);
	}
	

	return getGameState();
}

void SimonState::render(sf::RenderWindow& window) const
{
	window.draw(*this->p);
	for (int i = 0; i < nrOfTiles; i++) {
		if (this->testT[i]->getWannaDraw()) {
			window.draw(*this->testT[i]->getSprite());
		}
	}
	
	window.draw(this->bull);
	
}
