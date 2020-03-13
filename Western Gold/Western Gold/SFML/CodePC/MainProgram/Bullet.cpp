#include "Bullet.h"

bool Bullet::madeSound() const
{
	return bulletAt == bulletState::MADE_SOUND;
}

void Bullet::throwBullet(Player &player)
{
		this->setPosition(player.getPosition());
		this->setRotatioSprite(player.getRotation());
		bulletAt = bulletState::FLYING;
		
}

void Bullet::fly(DeltaTime time)
{
	if (currentflytime < flytime) {
		//move
		currentflytime += (float)time.dt();
		moveDir(time);
	}
	else {
		//bullet hit ground sound
		bulletAt = bulletState::MADE_SOUND;
	}
}

void Bullet::moveDir(DeltaTime time)
{
	double radias = (3.14159265359 / 180) * ((double)this->getRotation() - 90);
	this->moveSprite(sf::Vector2f(cos((float)radias), sin((float)radias)), (float)(speed * time.dt()));
}

void Bullet::followOutScreen(Player* p)
{
	this->setPosition(p->getPosition() + sf::Vector2f(1000.f, 1000.f));
}

Bullet::Bullet(ResourceManager* rm):
	GameObject(rm->getBullet(),rm)
{
	bulletAt = bulletState::PLAYER;
	this->flytime = 0.9f;
	this->currentflytime = 0;
	this->speed = 300;
	this->setSpriteScale(2);
}

Bullet::~Bullet()
{
}

bulletState Bullet::getBulletState()
{
/*
	0 = Player, 1 = Throw,  2 = Flying, 3 = Ground, 4 = MADE_SOUND
*/
	return bulletAt;
}

void Bullet::setBulletState(bulletState state)
{
	bulletAt = state;
}

void Bullet::update(DeltaTime time, Player* player)
{
	
	if (bulletAt == bulletState::MADE_SOUND) {
		currentflytime = 0;
		sound.PlaySounds(getRm()->getKlingSound());
		bulletAt = bulletState::GROUND;
	}
	if (bulletAt == bulletState::FLYING) {
		fly(time);
	}
	else if (bulletAt == bulletState::PLAYER) {
		followOutScreen(player);
	}
	//when on ground be able to pick it up

}
void Bullet::update(DeltaTime time) {
	//update needs to take in player but entity wants only time
}
