#include "GameState.h"



GameState::GameState(ResourceManager* rm):
	rm(rm)
{
}


GameState::~GameState()
{
}

ResourceManager* GameState::getRm() const
{
	return rm;
}
