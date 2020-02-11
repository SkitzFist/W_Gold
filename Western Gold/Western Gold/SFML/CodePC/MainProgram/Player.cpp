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

void Player::shoot()
{
}

void Player::rotation()
{
	sf::Vector2i mPos = sf::Mouse::getPosition(*this->window);
	float tanv = atan2f((mPos.y - this->getPosition().y) , (mPos.x - this->getPosition().x));
	this->rotateSprite(tanv);
}

Player::Player(sf::Texture* tex, ResourceManager* rm):
	Entity(tex,rm/*add col and row later*/)
{
	this->window = rm->getWindow();
	speed = 100;
}

Player::~Player()
{
}

void Player::update(DeltaTime time)
{
	move(time);
	rotation();
}
