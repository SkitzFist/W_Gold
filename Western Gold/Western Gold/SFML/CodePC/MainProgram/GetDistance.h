#pragma once
class GameObject;
template<typename T>
float getDistance(T x1, T x2) {
	return abs(x1 - x2);
}
template<typename T>
float getDistance(T x1, T y1, T x2, T y2) {
	return sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) *(y1 - y2));
}
float getDistance(GameObject* gameobj1, GameObject* gameobj2);