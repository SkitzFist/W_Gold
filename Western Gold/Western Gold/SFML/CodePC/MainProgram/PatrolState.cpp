#include "PatrolState.h"

//debug
#include <iostream>

EnemyState* PatrolState::update(DeltaTime delta)
{
	EnemyState* state = this;

	std::cout << "PatrolState" << std::endl;

	return state;
}
