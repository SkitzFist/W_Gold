#include "SimonState.h"
#include <iostream>
#include "Line.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	bull(rm)
	
{
	nrOfTiles = 8;
	
	p = new Player(rm->getCharacter(), rm, nrOfTiles, testT);
	enemytest = new Enemy*[1];
	enemytest[0] = new Enemy(getRm()->getEnemy(), getRm(), 1);
	enemytest[0]->setPosition(500, 50);
	setGameState(this);

	testT = new tile * [nrOfTiles];
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i] = new tile(sf::Vector2i(200, 200), true);
		testT[i]->setSprite(rm->getCharacter());
		testT[i]->setWorldPos(sf::Vector2f(100.0f * ((float)i + 1), 200.0f + i * 25.0f * (float)(sin(i) + 1)));
	}
	collision.setUpCollision(p, testT, enemytest, nrOfTiles, 1);
}

SimonState::~SimonState()
{
	for (int i = 0; i < nrOfTiles; i++) {
		delete testT[i];
	}
	delete[] testT;

	delete p;
	for (int i = 0; i < 1; i++) {/*nrofEnemies*/
		delete enemytest[i];
	}
	delete[] enemytest;
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
		if (collision.shootCollider(p)) {
			std::cout << "shoot an enemy" << std::endl;
		}
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
	window.draw(*this->enemytest[0]);
	
	window.draw(this->bull);
	
}
