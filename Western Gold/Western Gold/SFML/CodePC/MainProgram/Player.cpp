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
	sf::Vector2i mPos = sf::Mouse::getPosition();
	float v = (mPos.y - this->getTop()) / (mPos.x - this->getLeft());
	this->rotateSprite(v);
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
	rotation();
}
