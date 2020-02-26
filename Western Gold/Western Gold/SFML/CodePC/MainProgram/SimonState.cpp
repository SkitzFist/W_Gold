#include "SimonState.h"
#include <iostream>
#include "Line.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	bull(rm),
	lvl(rm, rm->getLevel_Test())
	
{
	nrOfTiles = 8;
	nrOfEnemies = 4;
	p = new Player(rm->getAnimationTest(), rm, nrOfTiles, testT);
	enemytest = new Enemy*[nrOfEnemies];
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i] = new Enemy(getRm()->getEnemy(), getRm(), 1, lvl.getGrid());
		enemytest[i]->setPosition(150 * i, 50);
	}


	testT = new tile * [nrOfTiles];
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i] = new tile(sf::Vector2i(100 * (i + 1), 200 + i * 25.0f * (float)(sin(i) + 1)), true,sf::Vector2i(10,10), rm->getCharacter());
	}
	collision.setUpCollision(p, testT, enemytest, nrOfTiles, nrOfEnemies);
}

SimonState::~SimonState()
{
	for (int i = 0; i < nrOfTiles; i++) {
		delete testT[i];
	}
	delete[] testT;

	delete p;
	for (int i = 0; i < nrOfEnemies; i++) {/*nrofEnemies*/
		delete enemytest[i];
	}
	delete[] enemytest;
}

GameState* SimonState::handleEvent(const sf::Event& event)
{
	GameState* state = this;


	return state;
}

GameState* SimonState::update(DeltaTime delta)
{
	GameState* state = this;

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
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i]->update(delta);
	}
	

	return state;
}

void SimonState::render(sf::RenderWindow& window) const
{
	window.draw(*this->p);
	for (int i = 0; i < nrOfTiles; i++) {
		if (this->testT[i]->getWannaDraw()) {
			window.draw(*this->testT[i]->getSprite());
		}
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		window.draw(*this->enemytest[i]);
	}
	
	window.draw(this->bull);
	
}
