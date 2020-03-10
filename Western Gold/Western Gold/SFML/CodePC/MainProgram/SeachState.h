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

	int maxSearchDistance;
	float maximumSearchTime;
	float minimumSearchTime;
	float searchTime;
	float searchTimer;

	void move();
	void calculatePath();
	sf::Vector2f getDir();
	bool hasReachedTile(tile* t);
	tile* getNextTarget();
	int randomInt(int min, int max);
	float randomFloat(float min, float max);
};