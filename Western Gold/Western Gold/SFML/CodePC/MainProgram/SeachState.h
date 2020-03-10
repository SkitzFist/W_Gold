#pragma once
#include "EnmState.h"
class SeachState:
	public EnmState
{
public:
	SeachState(Enemy* enemy, sf::Vector2f searchPos);
	// Inherited via EnmState
	virtual EnmState* update(DeltaTime time) override;

private:
	tile* currentTile;
	tile* targetTile;
	tile* nextTile;

	void move();
	void calculatePath();
	sf::Vector2f getDir();
	bool hasReachedTile(tile* t);
	tile* getNextTarget();
};

