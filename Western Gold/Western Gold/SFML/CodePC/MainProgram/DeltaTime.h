#pragma once
#include <chrono>

class DeltaTime {
private:
	double dpt;
	std::chrono::steady_clock::time_point t_start;
	std::chrono::steady_clock::time_point t_end;
public:
	DeltaTime();
	void restartClock();
	double dt()const;
};