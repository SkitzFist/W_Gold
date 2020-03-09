#pragma once
#include "EnmState.h"
#include "Player.h"

class AttackState:
	public EnmState
{
public:
	AttackState(Enemy* enemy, Player* player);
	// Inherited via EnmState
	virtual EnmState* update(DeltaTime time) override;

private:
	Player* player;
	float shootDistance;
	float timesBetweenShots;
	float shootingTimer;

	void shoot();
	bool canShoot();
	float getDistance(sf::Vector2f a, sf::Vector2f b);
	sf::Vector2f getDir();

	void move(DeltaTime time);
	tile* targetTile;
	tile* currentTile;
	tile* nextTile;
};

