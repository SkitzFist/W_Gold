#include "PlayState.h"
#include "PauseState.h"
#include "WinState.h"
#include "LoseState.h"


PlayState::PlayState(ResourceManager* rm) :
	GameState(rm),
	collision(rm),
	ui(rm)
{
	//config
	canStart = false;
	//setup
	nrOfBullets = 6;

	level = new Level(rm, rm->getLevel_01());

	player = new Player(rm->getCharacter(), rm, enemyHandler.getNrOf());
	player->setPosition(100.f, 100.f);
	level->placeEnemies(player, enemyHandler);
	level->placeGold(goldHandler);
	player->setEnemyRays(enemyHandler.getNrOf());
	player->setGoldRays(goldHandler.getNrOf());

	bullets = new Bullet*[nrOfBullets];
	for (int i = 0; i < nrOfBullets; i++) {
		bullets[i] = new Bullet(rm);
	}

	collision.setUpCollision(
		player,
		level->getGrid(),
		&enemyHandler,
		goldHandler.getGold(),
		bullets,
		goldHandler.getNrOf(),
		nrOfBullets
	);
	enemyHandler.setCollision(collision);
	rm->setView(&camera);
	rm->getDt()->restartClock();
	rm->getDt()->restartTimer();
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
	if (event.type == sf::Event::KeyPressed) {
		canStart = true;
	}
	
	else if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Escape) {
			state = new PauseState(getRm(), this);
		}
	}
	
	return state;
}

GameState * PlayState::update(DeltaTime delta)
{
	GameState* state = this;

	if (canStart) {
		//enemy
		for (int i = 0; i < enemyHandler.getNrOf(); i++) {
			player->getEnemyRay(i)->updateRay(player, enemyHandler.getEnemies()[i]);
			this->enemyHandler.getEnemies()[i]->setWannaDraw(true);
		}
		enemyHandler.update(delta);

	}

	//gold
	for (int i = 0; i < goldHandler.getNrOf(); i++) {
		if (!goldHandler.getGold()[i]->take()) {
			player->getGoldRay(i)->updateRay(player, goldHandler.getGold()[i]);
			goldHandler.getGold()[i]->setWannaDraw(true);
		}
	}
	goldHandler.update(delta);

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

	for (int i = 0; i < 6; ++i) {
		if (bullets[i]->getBulletState() == bulletState::MADE_SOUND) {
			enemyHandler.activateSearchState(bullets[i]->getPosition());
		}
	}

	//collision
	collision.update();

	for (int i = 0; i < enemyHandler.getNrOf(); i++) {
		collision.enemySeeCollider(enemyHandler.getEnemies()[i]);
	}

	ui.updateUI(player, delta);

	camera.setCenter(player->getPosition());

	if (collision.outSide() && player->getNrOfGold() >= NR_OF_GOLD_TO_WIN) {
		state = new WinState(getRm(), player->getNrOfGold());
		delete this;
	}
	else if (collision.outSide() && player->getNrOfGold() < NR_OF_GOLD_TO_WIN 
		|| player->isDead()){
		state = new LoseState(getRm(), this);
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
	for (int i = 0; i < goldHandler.getNrOf(); i++) {
		window.draw(*goldHandler.getGold()[i]);
	}
	window.draw(ui);
}
