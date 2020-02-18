#pragma once
#include "DeltaTime.h"


class EnemyState
{
public:
	virtual EnemyState* update(DeltaTime delta) = 0;
};