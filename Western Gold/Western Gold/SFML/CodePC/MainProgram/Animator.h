#pragma once
#include <SFML/Graphics.hpp>
#include "DeltaTime.h"

class Animator {
private:
	sf::Sprite *sprite;
	float timeBetween;
	float timeToNextFrame;
	int nrOfCol;
	int nrOfRows;
	int whatRow;
	sf::IntRect rect;
public:
	Animator();
	void setAnimation(sf::Sprite* sprite, float timeBetween, int nrOfCol, int nrOfRows, int whatRow);
	void updateAnimator(DeltaTime time);
	void changeRow(int whatRow);
	void changeNrOfCols(int nrOfCols);
};