#pragma once
#include "DeltaTime.h"
#include "Enemy.h"

class EnemyState
{
public:
	virtual EnemyState* update(DeltaTime delta) = 0;
};