#include "GameState.h"



GameState::GameState(ResourceManager* rm):
	rm(rm)
{
}


GameState::~GameState()
{
}

void GameState::setGameState(GameState* state)
{
	this->state = state;
}

GameState* GameState::getGameState() const
{
	return state;
}

ResourceManager* GameState::getRm() const
{
	return rm;
}
