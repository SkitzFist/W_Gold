#pragma once
#include "GameObject.h"
#include "Player.h"

class Bullet :public GameObject{
private:
	enum class bulletState
	{
		PLAYER, THROW ,FLYING, GROUND
	}; 
	bulletState bulletAt;
	float flytime;
	float currentflytime;
	float speed;
	
	void fly(DeltaTime time);
	void moveDir(DeltaTime time);
public:
	void throwBullet(DeltaTime time, Player &player);
	Bullet(ResourceManager* rm);
	virtual ~Bullet();
	int getBulletState();
	void update(DeltaTime time);
};