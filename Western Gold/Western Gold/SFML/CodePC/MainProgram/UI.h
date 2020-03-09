#pragma once
#include "Button.h"
#include "Text.h"
#include "ResourceManager.h"

class UI : public sf::Drawable 
{
private:
	/*
	Exit,
	Cylinder
	Shotts
	*/
	Button exit;
	sf::Vector2f exitButtonPos;

	sf::Sprite cylinder;
	sf::Vector2f cylinderPos;

	sf::Sprite *shots;

	int nrOfShots;
public:

	UI(ResourceManager* rm);
	void updateUI(sf::Vector2f playerPos);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};