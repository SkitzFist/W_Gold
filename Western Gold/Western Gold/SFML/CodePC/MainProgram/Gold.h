#pragma once
#include "GameObject.h"

class Gold : public GameObject {
private:
	bool taken;
public:
	Gold(ResourceManager *rm, float xPos, float yPos);
	void update(DeltaTime time);
	bool take(bool taken = false);
	sf::FloatRect getBounds()const;
};

