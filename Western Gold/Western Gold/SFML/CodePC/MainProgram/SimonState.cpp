#include "SimonState.h"
#include <iostream>
#include "Line.h"
#include "UI.h"
#include <thread>

SimonState::SimonState(ResourceManager* rm)
	:
	GameState(rm),
	lvl(rm, rm->getLevel_01()),
	ui(rm),
	collision(rm)
{
	//nrOfObjects
	nrOfWalkableTiles = lvl.getGrid()->getNrOfWalkableTiles();
	nrOfNonWalkableTiles = lvl.getGrid()->getNrOfNotWalkableTiles();
	nrOfEnemies = 1;
	nrOfGold = 3;
	nrOfBullets = 6;
	
	//objects initialize
	p = new Player(rm->getAnimationTest(), rm, nrOfEnemies, nrOfGold);
	p->setEnemyRays(nrOfEnemies);
	p->setPosition(100, 100);
	gold = new Gold * [nrOfGold];
	WalkableT = new tile*[lvl.getGrid()->getNrOfWalkableTiles()];
	notWalkableT = new tile*[lvl.getGrid()->getNrOfNotWalkableTiles()];
	enemytest = new Enemy * [nrOfEnemies];
	bull = new Bullet*[6];
	
	//create objects
	for (int i = 0; i < nrOfGold; i++) {
		gold[i] = new Gold(rm, (float)(i+1) * 100.0f, 300.0f + (float)i * 100.0f);
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i] = new Enemy(getRm(), 45, lvl.getGrid(), p);
		enemytest[i]->setPosition(500,550);
		enemytest[i]->setRotatioSprite(2);
		//enemytest[i]->engagePatrolState(patrollPos, static_cast<size_t>(2));
	}
	//Tiles
	int n = 0; 
	int n2 = 0;
	for (int y = 0; y < (int)lvl.getGrid()->getGridSize().y; y++) {
		for (int x = 0; x < (int)lvl.getGrid()->getGridSize().x; x++) {
			if (!lvl.getGrid()->getTiles()[y][x].getIsWalkable()) {
				notWalkableT[n2] = &lvl.getGrid()->getTiles()[y][x];
				n2++;
			}
		}
	}
	//bullet
	for (int i = 0; i < nrOfBullets; i++) {
		bull[i] = new Bullet(rm);
	}
	
	//setup collision
	collision.setUpCollision(p, lvl.getGrid(), enemytest, gold, bull, nrOfEnemies, nrOfGold, nrOfBullets);
	
	rm->setView(&camera);
	
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
	for (int i = 0; i < nrOfBullets; i++) {
		delete bull[i];
	}
	delete[] bull;
	
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
		enemytest[0]->addRotationSprite(100.f * (float)delta.dt());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		enemytest[0]->addRotationSprite(-100.f * (float)delta.dt());
	}
	
	//player
	p->update(delta);
	if (p->tossBullet()) {
		bool toss = false;
		for (int i = 0; i < 6 && !toss; i++) {
			if (bull[i]->getBulletState() == bulletState::PLAYER) {
				toss = true;
				bull[i]->throwBullet(*p);
			}
		}
	}
	if (p->shoot()) {
		//check what he shot
		if (collision.shootCollider(p)) {
			std::cout << "shoot an enemy" << std::endl;
		}
	}
	for (int i = 0; i < nrOfBullets; i++) {
		bull[i]->update(delta, p);
	}
	//enemy
	for (int i = 0; i < nrOfEnemies; i++) {
		enemytest[i]->update(delta);
	}
	
	for(int i = 0; i < nrOfEnemies; i++){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << "stop" << std::endl;
		}
		if (collision.enemySeeCollider(enemytest[i])) {
			std::cout << "see player" << std::endl;
		}
	}
	
	
	//gold
	for (int i = 0; i < nrOfGold; i++) {
		gold[i]->update(delta);
	}
	
	//other
	camera.setCenter((float)(int)p->getPosition().x ,(float)(int)p->getPosition().y);
	
	collision.update();
	
	ui.updateUI(p, delta);
	
	return state;
}

void SimonState::render(sf::RenderWindow& window) const
{
	window.setView(camera);
	lvl.drawLevel(window);
	
	for (int i = 0; i < nrOfGold; i++) {
		if (!gold[i]->take()) {
			window.draw(*this->gold[i]);
		}
	}
	for (int i = 0; i < nrOfEnemies; i++) {
		window.draw(*this->enemytest[i]);
	}
	for (int i = 0; i < nrOfBullets; i++) {
		window.draw(*this->bull[i]);
	}
	window.draw(*this->p);
	window.draw(this->ui);
}
