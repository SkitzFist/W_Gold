#include "EnmState.h"

EnmState::EnmState(Enemy* enm)
{
	this->enm = enm;
}

EnmState::~EnmState()
{
	enm = nullptr;
}

Enemy* EnmState::getEnm() const
{
	return enm;
}
