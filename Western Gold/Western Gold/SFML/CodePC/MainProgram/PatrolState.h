#pragma once
#include "EnemyState.h"
class PatrolState :
	public EnemyState
{
public:
	// Inherited via EnemyState
	virtual EnemyState* update(DeltaTime delta) override;
};

