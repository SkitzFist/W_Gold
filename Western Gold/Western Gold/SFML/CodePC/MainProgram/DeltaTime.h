#pragma once
#include <chrono>

class DeltaTime {
private:
	double dpt;
	std::chrono::steady_clock::time_point t_start;
	std::chrono::steady_clock::time_point t_end;
	double slowTime;
	float totalTime;
public:
	DeltaTime();
	void restartClock();
	void restartTimer();
	float getTotalTime()const;
	double dt()const;
	void playWithTime(float slowmo);
	double getRawTime()const;
};