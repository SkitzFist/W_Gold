#include "PlayState.h"



PlayState::PlayState(ResourceManager* rm) :
	GameState(rm),
	collision(rm),
	ui(rm)
{
	//config
	canStart = false;
	//setup
	//objects
	nrOfBullets = 6;

	level = new Level(rm, rm->getLevel_01());
	

	player = new Player(rm->getAnimationTest(), rm, enemyHandler.getNrOf(), 0);
	player->setPosition(600.f, 600.f);
	level->placeEnemies(player, enemyHandler);
	level->placeGold(goldHandler);
	player->setEnemyRays(enemyHandler.getNrOf());

	bullets = new Bullet*[nrOfBullets];
	for (int i = 0; i < nrOfBullets; i++) {
		bullets[i] = new Bullet(rm);
	}

	collision.setUpCollision(
		player,
		level->getGrid(),
		&enemyHandler,
		nullptr,
		bullets,
		0,
		nrOfBullets
	);

	rm->setView(&camera);
}


PlayState::~PlayState()
{
	delete player;
	delete level;
	for (int i = 0; i < nrOfBullets; i++) {
		delete bullets[i];
	}
	delete[] bullets;
}

GameState * PlayState::handleEvent(const sf::Event & event)
{
	GameState* state = this;
	if (event.type == event.KeyReleased) {
		if (event.key.code == sf::Keyboard::Space) {
			canStart = true;
		}
	}
	return state;
}

GameState * PlayState::update(DeltaTime delta)
{
	GameState* state = this;
	//enemy
	if (canStart) {

		for (int i = 0; i < enemyHandler.getNrOf(); i++) {
			player->getEnemyRay(i)->updateRay(player, enemyHandler.getEnemies()[i]);
		}
		//for (int i = 0; i < nrOfGold; i++) {
		//	p->getGoldRay(i)->updateRay(p, gold[i]);
		//}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << enemyHandler.getEnemies()[0]->getRotation() << std::endl;
			//std::cout << ((atan2f(0 - dir.y, 0 - dir.y) * 180) / 3.14 + 90) << std::endl;
		}
		enemyHandler.update(delta);
		for (int i = 0; i < enemyHandler.getNrOf(); i++) {
			this->enemyHandler.getEnemies()[i]->setWannaDraw(true);
		}
		for (int i = 0; i < nrOfBullets; i++) {
			bullets[i]->update(delta, player);
		}
		
		//player
		player->update(delta);
		if (player->shoot()) {
			//check what he shot
			collision.shootCollider(player);
		}
		
		if (player->tossBullet()) {
			bool toss = false;
			for (int i = 0; i < 6 && !toss; i++) {
				if (bullets[i]->getBulletState() == bulletState::PLAYER) {
					toss = true;
					bullets[i]->throwBullet(*player);
				}
			}
		}

		//Gold
		goldHandler.update(delta);
		
		//collision
		collision.update();
		
		for (int i = 0; i < enemyHandler.getNrOf(); i++) {
			if (collision.enemySeeCollider(enemyHandler.getEnemies()[i])) {
			}
		}

		ui.updateUI(player, delta);

		camera.setCenter(player->getPosition());
	}
	return state;
}

void PlayState::render(sf::RenderWindow&  window) const
{
	
	window.setView(camera);
	level->drawLevel(window);
	window.draw(*player);
	
	for (int i = 0; i < nrOfBullets; i++) {
		window.draw(*bullets[i]);
	}
	for (int i = 0; i < enemyHandler.getNrOf(); ++i) {
		window.draw(*enemyHandler.getEnemies()[i]);
	}
	for (int i = 0; i < goldHandler.getNrOf(); ++i){
		window.draw(*goldHandler.getGold()[i]);
	}
	window.draw(ui);
	//debug
}
