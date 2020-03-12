#include "SimonState.h"
#include <iostream>
#include "Line.h"
#include "UI.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm),
	bull(rm),
	lvl(rm, rm->getLevel_01()),
	ui(rm)
{
	//nrOfObjects
	nrOfWalkableTiles = lvl.getGrid()->getNrOfWalkableTiles();
	nrOfNonWalkableTiles = lvl.getGrid()->getNrOfNotWalkableTiles();
	nrOfEnemies = 1;
	nrOfGold = 3;
	
	//objects initialize
	p = new Player(rm->getAnimationTest(), rm, lvl.getGrid()->getNrOfWalkableTiles(), nrOfEnemies, nrOfGold);
	p->setPosition(100, 100);
	gold = new Gold * [nrOfGold];
	WalkableT = new tile*[lvl.getGrid()->getNrOfWalkableTiles()];
	notWalkableT = new tile*[lvl.getGrid()->getNrOfNotWalkableTiles()];
	enemytest = new Enemy * [nrOfEnemies];
	
	
	//create objects
	for (int i = 0; i < nrOfGold; i++) {
		gold[i] = new Gold(rm, (float)(i+1) * 100.0f, 300.0f + (float)i * 100.0f);
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i] = new Enemy(getRm(), 90, lvl.getGrid(), p);
		enemytest[i]->setPosition(200,200);
		enemytest[i]->setRotatioSprite(2);
		//enemytest[i]->engagePatrolState(patrollPos, static_cast<size_t>(2));
	}
	//Tiles
	int n = 0; 
	int n2 = 0;
	for (int y = 0; y < lvl.getGrid()->getGridSize().y; y++) {
		for (int x = 0; x < lvl.getGrid()->getGridSize().x; x++) {
			if (!lvl.getGrid()->getTiles()[y][x].getIsWalkable()) {
				notWalkableT[n2] = &lvl.getGrid()->getTiles()[y][x];
				n2++;
			}
		}
	}
	int pb = (lvl.getGrid()->getGridSize().x) * (lvl.getGrid()->getGridSize().y);
	//setup collision
	collision.setUpCollision(p, lvl.getGrid(), enemytest, gold, nrOfEnemies, nrOfGold);
	
	
	
}

SimonState::~SimonState()
{
	delete p;

	for (int i = 0; i < nrOfEnemies; i++) {
		delete enemytest[i];
	}
	delete[] enemytest;

	for (int i = 0; i < nrOfGold; i++) {
		delete gold[i];
	}
	delete[] gold;

	delete[] WalkableT;
	delete[] notWalkableT;
	
}

GameState* SimonState::handleEvent(const sf::Event& event)
{
	GameState* state = this;

	//ass
	return state;
}

GameState* SimonState::update(DeltaTime delta)
{
	GameState* state = this;
	//tiles
	for (int i = 0; i < lvl.getGrid()->getNrOfNotWalkableTiles(); i++) {
		this->notWalkableT[i]->setWannaDraw(true);
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i]->setWannaDraw(true);
	}
	for (int i = 0; i < nrOfGold; i++) {

		gold[i]->setWannaDraw(true);
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		p->getEnemyRay(i)->updateRay(p, enemytest[i]);
	}
	for (int i = 0; i < nrOfGold; i++) {
		p->getGoldRay(i)->updateRay(p, gold[i]);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		enemytest[0]->addRotationSprite(100 * delta.dt());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		enemytest[0]->addRotationSprite(-100 * delta.dt());
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
		if (collision.enemySeeCollider(enemytest[i])) {
			std::cout << "see player" << std::endl;
		}
		//if (enemytest[i])) {
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
