#include "Bullet.h"

void Bullet::throwBullet(DeltaTime time, Player player)
{
	bulletAt = bulletState::FLYING;

}

Bullet::Bullet(ResourceManager* rm):
	GameObject(rm->getBullet(),rm)
{
	bulletAt = bulletState::PLAYER;
}

Bullet::~Bullet()
{
}

int Bullet::getBulletState()
{
	return (int)bulletAt;
}

void Bullet::update(DeltaTime time, Player player)
{
	throwBullet(time, player);
	if (bulletAt == bulletState::FLYING) {
		//count down so it reaches ground
	}
	//when on ground be able to pick it up
}
