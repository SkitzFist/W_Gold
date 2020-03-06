#include "Gold.h"

Gold::Gold(ResourceManager *rm, float xPos, float yPos):
	GameObject(rm->getGold(), rm)
{
	this->setPosition(xPos, yPos);
	this->setanimation(0.12f, 8, 2, 1);
	this->setSpriteScale(2);
	this->taken = false;
}

void Gold::update(DeltaTime time)
{
	animator.updateAnimator(time);
}

bool Gold::take(bool taken)
{
	//can both change and return what ever it is taken or not
	if (taken) {
		this->taken = taken;
	}
	return this->taken;
}

sf::FloatRect Gold::getBounds() const
{
	return GameObject::getBounds();
}
