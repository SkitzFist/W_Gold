#include "testObj.h"
#include <iostream>

test::test(ResourceManager* rm):
	GameObject(rm->gettex(), rm)
{
	std::cout << "loading test" << std::endl;
}

void test::update(DeltaTime delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->sound.PlaySounds(getRm()->getass());
	}
}
