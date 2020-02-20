#pragma once
template<typename T>
float getDistance(T x1, T x2) {
	return abs(x1 - x2);
}
template<typename T>
float getDistance(T x1, T y1, T x2, T y2) {
	return sqrtf((abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2) * abs(y1 - y2)));
}