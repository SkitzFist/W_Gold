#pragma once
#include "Button.h"
#include "Text.h"
#include "ResourceManager.h"
#include "DeltaTime.h"
#include "Player.h"
#include <sstream>
#include <iostream>
#include <iomanip>//setprecision

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
	sf::Text text;

	sf::Text time;

	int nrOfShots;
public:

	UI(ResourceManager* rm);
	virtual ~UI();
	void updateUI(Player *player, DeltaTime time);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};