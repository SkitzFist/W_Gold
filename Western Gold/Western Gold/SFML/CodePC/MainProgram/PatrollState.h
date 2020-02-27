#pragma once
#include "EnmState.h"

class PatrollState:
	public EnmState
{
public:
	PatrollState(Enemy* enm, sf::Vector2i* patrollPoints, size_t patrollPointsLength);
	virtual ~PatrollState();
	// Inherited via EnmState
	virtual EnmState* update(DeltaTime time) override;

private:
	tile** patrollTiles;
	size_t patrollTilesLength;

	tile* currentTile;
	tile* nextTile;
	tile* targetTile;

	void move(DeltaTime time);
	void setupPatrollTiles(sf::Vector2i* patrollPoints);
	void calculatePath();
	bool hasReachedTile(tile* t);
	sf::Vector2f getDir();
};

