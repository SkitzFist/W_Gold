#include "Player.h"

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
		int nowSpeed = speed;
		if (movementKeys >= 2) {
			nowSpeed /= 2;
		}
		this->moveSprite(time.dt() * speed * xDir, time.dt() * speed * yDir);
	}
}

void Player::shoot()
{
}

void Player::rotation()
{
}

Player::Player(sf::Texture* tex, ResourceManager* rm):
	Entity(tex,rm/*add col and row later*/)
{
	speed = 100;
}

//Player::~Player()
//{
//}

void Player::update(DeltaTime time)
{
	move(time);
}
