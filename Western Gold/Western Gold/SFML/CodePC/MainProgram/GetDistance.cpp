#include "GetDistance.h"
#include "GameObject.h"

float getDistance(GameObject* gameobj1, GameObject* gameobj2)
{
	float distance = (gameobj1->getPosition().x - gameobj2->getPosition().x) *
		(gameobj1->getPosition().x - gameobj2->getPosition().x) +
		(gameobj1->getPosition().y - gameobj2->getPosition().y) *
		(gameobj1->getPosition().y - gameobj2->getPosition().y);
	return distance;
}
