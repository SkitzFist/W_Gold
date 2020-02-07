#pragma once
#include "GameObject.h"
#include "ResourceManager.h"
#include "DeltaTime.h"

class test : public GameObject{
private:
	Sound sound;
public:
	test(ResourceManager *rm);
	void update(DeltaTime delta);
};