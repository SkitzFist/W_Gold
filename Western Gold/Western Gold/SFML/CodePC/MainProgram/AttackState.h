#pragma once
#include "EnmState.h"
#include "Player.h"

class AttackState:
	public EnmState
{
public:
	AttackState(Enemy* enemy, Player* player);
	virtual ~AttackState() override;
	// Inherited via EnmState
	virtual EnmState* update(DeltaTime time) override;

private:
	Player* player;
	float shootDistance;
	float timesBetweenShots;
	float shootingTimer;

	tile* targetTile;
	tile* currentTile;
	tile* nextTile;
	float playerMaxDistance;

	void shoot();
	bool canShoot();
	float getDistance(sf::Vector2f a, sf::Vector2f b);
	sf::Vector2f getDir();

	void move(DeltaTime time);
	bool hasReachedTile(tile* t);
	void calculatePath();
};

