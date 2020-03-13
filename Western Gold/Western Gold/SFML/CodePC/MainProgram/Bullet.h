#pragma once
#include "GameObject.h"
#include "Player.h"

enum class bulletState
{
	PLAYER, THROW, FLYING, GROUND, MADE_SOUND
};
class Bullet :public GameObject{
private:
	 
	bulletState bulletAt;
	float flytime;
	float currentflytime;
	float speed;

	void fly(DeltaTime time);
	void moveDir(DeltaTime time);
	void followOutScreen(Player* p);
public:
	bool madeSound()const;
	void throwBullet(Player &player);
	Bullet(ResourceManager* rm);
	virtual ~Bullet();
	bulletState getBulletState();
	void setBulletState(bulletState state);
	void update(DeltaTime time, Player* p);
	void update(DeltaTime time);
};