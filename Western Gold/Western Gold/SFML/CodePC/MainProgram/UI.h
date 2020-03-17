#pragma once
#include "Button.h"
#include "Text.h"
#include "ResourceManager.h"
#include "DeltaTime.h"
#include "Player.h"
#include <sstream>
#include <iostream>
#include <iomanip>//setprecision
#include "Gold.h"

class UI : public sf::Drawable 
{
private:

	sf::Sprite cylinder;
	sf::Vector2f cylinderPos;

	sf::Sprite *shots;
	sf::Text text;

	sf::Text time;

	sf::Text nrOfGold;
	Gold gold;

	int nrOfShots;
	ResourceManager* rm;
public:

	UI(ResourceManager* rm);
	virtual ~UI();
	void updateUI(Player *player, DeltaTime time);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};