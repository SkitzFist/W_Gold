#include "Bullet.h"

void Bullet::throwBullet(DeltaTime time, Player &player)
{
		this->setPosition(player.getPosition());
		this->setRotatioSprite(player.getRotation());
		bulletAt = bulletState::FLYING;
		
}

void Bullet::fly(DeltaTime time)
{
	
	if (bulletAt == bulletState::FLYING) {
		if (currentflytime < flytime) {
			//move
			currentflytime += (float)time.dt();
			moveDir(time);
		}
		else {
			currentflytime = 0;
			bulletAt = bulletState::GROUND;
		}
		

	}
}

void Bullet::moveDir(DeltaTime time)
{
	double radias = (3.14159265359 / 180) * ((double)this->getRotation() - 90);
	this->moveSprite(sf::Vector2f(cos((float)radias), sin((float)radias)), (float)(speed * time.dt()));
}

Bullet::Bullet(ResourceManager* rm):
	GameObject(rm->getBullet(),rm)
{
	bulletAt = bulletState::PLAYER;
	this->flytime = 2.0f;
	this->currentflytime = 0;
	this->speed = 100;
}

Bullet::~Bullet()
{
}

int Bullet::getBulletState()
{
	return (int)bulletAt;
}

void Bullet::update(DeltaTime time)
{
	fly(time);
	if (bulletAt == bulletState::FLYING) {
		//count down so it reaches ground

	}
	//when on ground be able to pick it up

}
