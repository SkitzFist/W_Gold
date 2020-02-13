#pragma once
#include "GameObject.h"
#include "Player.h"

class Bullet :public GameObject{
private:
	enum class bulletState
	{
		PLAYER, FLYING, GROUND
	}; 
	bulletState bulletAt;
	void throwBullet(DeltaTime time, Player player);
public:
	Bullet(ResourceManager* rm);
	virtual ~Bullet();
	int getBulletState();
	void update(DeltaTime time, Player player);
};