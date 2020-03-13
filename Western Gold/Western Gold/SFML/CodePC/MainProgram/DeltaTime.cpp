#include "DeltaTime.h"

DeltaTime::DeltaTime()
{
	//initilise clock start and end for calculations
	this->dpt = 0.0f;
	this->slowTime = 1.0f;
	this->totalTime = 0.0f;
	this->t_start = std::chrono::steady_clock::now();
	this->t_end = std::chrono::steady_clock::now();
}

void DeltaTime::restartClock()
{
	//calculate how much last frame was
	this->t_end = std::chrono::steady_clock::now();
	std::chrono::duration<double> runTime = this->t_end - this->t_start;
	this->dpt = runTime.count() * slowTime;
	this->t_start = std::chrono::steady_clock::now();
	totalTime += (float)(dpt / slowTime);
}

float DeltaTime::getTotalTime() const
{
	return totalTime;
}

double DeltaTime::dt()const
{
	//getting the deltaTime
	return dpt;
}

void DeltaTime::playWithTime(float slowmo)
{
	//can also make time faster
	this->dpt *= slowmo;
	this->slowTime = slowmo;
}

double DeltaTime::getRawTime() const
{
	double theReturn = dpt;
	if ((slowTime != 0) && (slowTime != 1)) {
		theReturn = this->dpt / slowTime;
	}
	return theReturn;
}



