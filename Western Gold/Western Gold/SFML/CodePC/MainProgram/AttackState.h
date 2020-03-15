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

	float playerDistanceBeforeCalcNewPath;

	sf::Vector2f playerLastPos;

	void shoot();
	bool canShoot();
	float getDistance(sf::Vector2f a, sf::Vector2f b);

	void move(DeltaTime time);
	void setNextTargetTile();

	double timer;
	double timeBeforeChangeState;
};

