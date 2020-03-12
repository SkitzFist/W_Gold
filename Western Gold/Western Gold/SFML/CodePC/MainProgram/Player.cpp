#include "Player.h"
#include <iostream>

void Player::move(DeltaTime time)
{
	int movementKeys = 0;
	int xDir = 0;
	int yDir = 0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		xDir--;
		movementKeys++;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		yDir--;
		movementKeys++;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		xDir++;
		movementKeys++;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		yDir++;
		movementKeys++;
	}
	//If player as two keys down move half speed
	if (movementKeys > 0) {
		float nowSpeed = speed;
		if (movementKeys >= 2) {
			nowSpeed /= 2;
		}
		this->moveSprite((float)time.dt() * speed * xDir, (float)time.dt() * speed * yDir);
	}
}



bool Player::shoot()
{
	bool theReturn = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !shooting) {
		shooting = true;
		if (nrOfShoots > 0) {
			nrOfShoots--;
			//shoot
			theReturn = true;
			this->sound.PlaySounds(getRm()->getGunShot());
		}
		else {
			//klick
		}
		
	}
	if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
		shooting = false;
		theReturn = false;
	}
	return theReturn;
}

bool Player::tossBullet()
{
	bool theReturn = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !tossing) {
		tossing = true;
		if (nrOfShoots > 0) {
			nrOfShoots--;
			//shoot
			theReturn = true;
		}
	}
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::H))) {
		tossing = false;
		theReturn = false;
	}
	
	return theReturn;
}

//Ray* Player::getTileRay(int nr)
//{
//	//return rayTile[nr];
//}


Ray* Player::getEnemyRay(int nr)
{
	return enemyRays[nr];
}

void Player::rotation()
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mPos = window->mapPixelToCoords(pixelPos);
	float tanv = atan2f((mPos.y - this->getPosition().y) , (mPos.x - this->getPosition().x));
	this->rotateSprite(tanv);
}

Player::Player(sf::Texture* tex, ResourceManager* rm, int nrOfTiles, int nrOfEnemies):
	Entity(tex,rm/*add col and row later*/,1)
{
	nrOfShoots = 6;
	shooting = false;
	tossing = false;

	//rayTile = new Ray * [nrOfTiles];
	//for (int i = 0; i < nrOfTiles; i++) {
	//	rayTile[i] = new Ray();
	//}
	//this->nrOfTiles = nrOfTiles;

	enemyRays = new Ray * [nrOfEnemies];
	for (int i = 0; i < nrOfEnemies; i++) {
		enemyRays[i] = new Ray();
	}
	this->nrOfEnemies = nrOfEnemies;

	this->window = rm->getWindow();
	speed = 100;

	this->setanimation(0.05f, 24, 1, 0);
}

Player::~Player()
{
	//for (int i = 0; i < nrOfTiles; i++) {
	//	delete rayTile[i];
	//}
	//delete[] rayTile;

	for (int i = 0; i < nrOfEnemies; i++) {
		delete enemyRays[i];
	}
	delete[] enemyRays;
}

void Player::update(DeltaTime time)
{
	move(time);
	rotation();
	animator.updateAnimator(time);
	Entity::update(time);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);
	//debug
	//for (int i = 0; i < nrOfTiles; i++) {
	//	target.draw(*this->rayTile[i]);
	//}
	for (int i = 0; i < nrOfEnemies; i++) {
		target.draw(*this->enemyRays[i]);
	}
}
