#pragma once
#include "EnmState.h"
class SearchState :
	public EnmState
{
public:
	SearchState(Enemy* enm, sf::Vector2f searchPos);
	// Inherited via EnmState
	virtual EnmState* update(DeltaTime time) override;

private:
	tile* targetTile;
	tile* currentTile;
	tile* nextTile;
};

