#pragma once
#include "EnmState.h"

class PatrollState:
	public EnmState
{
public:
	PatrollState(Enemy* enm);
	virtual ~PatrollState();
	// Inherited via EnmState
	virtual EnmState* update(DeltaTime time) override;

private:
	void move(DeltaTime time);
	void setNextTarget();
	double timer;
	double maxTime;
};

