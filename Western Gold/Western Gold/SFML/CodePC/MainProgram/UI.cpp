#include "UI.h"
#include <iostream>

UI::UI(ResourceManager *rm):
	exit(rm->getBasicFont(), "X", sf::Vector2f(0,0))
{
	exitButtonPos.x = (rm->getWindowWidth() / 2) - 20;
	exitButtonPos.y = -(rm->getWindowHeight()) + 220;
	nrOfShots = 6;
	cylinder.setTexture(*rm->getCylinder());
	cylinder.setScale(1.5f, 1.5f);
	cylinderPos.x = (rm->getWindowWidth() / 2) - (cylinder.getGlobalBounds().width + 10);
	cylinderPos.y = 370;
	this->shots = new sf::Sprite[nrOfShots];
	for (int i = 0; i < nrOfShots; i++) {
		shots[i].setTexture(*rm->getBullet());
		shots[i].setScale(20, 20);
	}
}

void UI::updateUI(sf::Vector2f playerPos)
{
	cylinder.setPosition(playerPos + cylinderPos);
	exit.setPosition(playerPos.x + exitButtonPos.x, playerPos.y + exitButtonPos.y);
	shots[0].setPosition(playerPos + cylinderPos + sf::Vector2f(50, 50));
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < nrOfShots; i++) {
		target.draw(shots[i]);
	}
	target.draw(cylinder);
	target.draw(exit);
}