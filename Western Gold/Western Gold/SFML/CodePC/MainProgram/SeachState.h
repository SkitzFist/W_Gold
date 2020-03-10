#pragma once
#include "EnmState.h"
class SeachState:
	public EnmState
{
public:
	SeachState(Enemy* enemy, sf::Vector2f searchPos);
	// Inherited via EnmState
	virtual EnmState* update(DeltaTime time) override;
};

