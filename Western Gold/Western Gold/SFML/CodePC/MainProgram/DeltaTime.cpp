#include "DeltaTime.h"

DeltaTime::DeltaTime()
{
	//initilise clock start and end for calculations
	this->dpt = 0.0f;
	this->t_start = std::chrono::steady_clock::now();
	this->t_end = std::chrono::steady_clock::now();
}

void DeltaTime::restartClock()
{
	//calculate how much last frame was
	this->t_end = std::chrono::steady_clock::now();
	std::chrono::duration<double> runTime = this->t_end - this->t_start;
	this->dpt = runTime.count();
	this->t_start = std::chrono::steady_clock::now();
}

double DeltaTime::dt()const
{
	//getting the deltaTime
	return dpt;
}



