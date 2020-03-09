#include "SimonState.h"
#include <iostream>
#include "Line.h"
#include "UI.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	bull(rm),
	lvl(rm, rm->getLevel_Test03()),
	ui(rm)
{
	//nrOfObjects
	nrOfTiles = 8;
	nrOfEnemies = 5;
	nrOfGold = 3;
	
	//objects initialize
	p = new Player(rm->getAnimationTest(), rm, nrOfTiles, nrOfEnemies);
	gold = new Gold * [nrOfGold];
	testT = new tile * [nrOfTiles];
	enemytest = new Enemy * [nrOfEnemies];
	
	//things needed to create some objects
	sf::Vector2i* patrollPos = new sf::Vector2i[2];
	patrollPos[0] = { 48,48 };
	patrollPos[1] = { 240, 48 };
	
	//create objects
	for (int i = 0; i < nrOfGold; i++) {
		gold[i] = new Gold(rm, (float)(i+1) * 100.0f, 300.0f + (float)i * 100.0f);
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i] = new Enemy(getRm()->getEnemy(), getRm(), 90, lvl.getGrid(), p);
		enemytest[i]->setPosition((float)(i+1) * 100.f, 48.f + (float)(sin(i) + 1) * 100.f);
		//enemytest[i]->engagePatrolState(patrollPos, static_cast<size_t>(2));
	}
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i] = new tile(sf::Vector2i((int)(100.f * (float)(i + 1)), (int)(200.f + (float)(i * 25.0f) * (float)(sin(i) + 1)) + 100), true, sf::Vector2i(10,10), rm->getCharacter());
	}
	int pb = (lvl.getGrid()->getGridSize().x) * (lvl.getGrid()->getGridSize().y);
	//setup collision
	collision.setUpCollision(p, lvl.getGrid(), enemytest, gold, nrOfEnemies, nrOfGold);
	
	
	
	//other
	delete[] patrollPos;
}

SimonState::~SimonState()
{
	delete p;

	for (int i = 0; i < nrOfTiles; i++) {
		delete testT[i];
	}
	delete[] testT;

	for (int i = 0; i < nrOfEnemies; i++) {
		delete enemytest[i];
	}
	delete[] enemytest;

	for (int i = 0; i < nrOfGold; i++) {
		delete gold[i];
	}
	delete[] gold;
}

GameState* SimonState::handleEvent(const sf::Event& event)
{
	GameState* state = this;


	return state;
}

GameState* SimonState::update(DeltaTime delta)
{
	GameState* state = this;
	//tiles
	for (int i = 0; i < nrOfTiles; i++) {
		testT[i]->setWannaDraw(true);
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i]->setWannaDraw(true);
	}
	for (int i = 0; i < nrOfTiles; i++) {
		p->getTileRay(i)->updateRay(p, testT[i]);
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		p->getEnemyRay(i)->updateRay(p, enemytest[i]);
	}
	
	//player
	p->update(delta);
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
	bull.update(delta);
	//enemy
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i]->update(delta);
	}
	
	for(int i = 0; i < nrOfEnemies; i++){
		//if (enemytest[i]->set)) {
		//
		//}
		//if (enemytest[i]->seePlayer(collision.shootCollider(enemytest[i]), delta)) {
		//	enemytest[i]->rotateTowards(p, delta);
		//	if (enemytest[i]->isShooting()) {
		//		enemytest[i]->seePlayer(collision.shootCollider(enemytest[i], true), delta);
		//	}
		//}
	}
	
	
	//gold
	for (int i = 0; i < nrOfGold; i++) {
		gold[i]->update(delta);
	}
	
	//other
	camera.setCenter(p->getPosition());

	collision.update();
	
	ui.updateUI(p->getPosition());
	
	return state;
}

void SimonState::render(sf::RenderWindow& window) const
{
	window.setView(camera);
	lvl.drawLevel(window);
	for (int i = 0; i < nrOfTiles; i++) {
		if (this->testT[i]->getWannaDraw()) {
			window.draw(*this->testT[i]->getSprite());
		}
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		window.draw(*this->enemytest[i]);
	}
	for (int i = 0; i < nrOfGold; i++) {
		if (!gold[i]->take()) {
			window.draw(*this->gold[i]);
		}
	}
	window.draw(this->bull);
	window.draw(*this->p);
	window.draw(this->ui);
}
