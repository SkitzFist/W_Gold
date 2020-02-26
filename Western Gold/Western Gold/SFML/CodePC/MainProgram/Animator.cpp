#include "Animator.h"
#include <iostream>

Animator::Animator()
{
	nrOfCol = 1;
	whatRow = 1;
	timeToNextFrame = 0;
	timeBetween = 1;
	this->nrOfRows = 1;
	sprite = nullptr;
}

void Animator::setAnimation(sf::Sprite* sprite, float timeBetween, int nrOfCol, int nrOfRows, int whatRow)
{
	this->sprite = sprite;
	this->nrOfRows = nrOfRows;
	this->timeBetween = timeBetween;
	this->timeToNextFrame = timeBetween;
	this->rect = sf::IntRect(0, whatRow * (sprite->getGlobalBounds().height / nrOfRows), (int)(sprite->getGlobalBounds().width / nrOfCol), (int)(sprite->getGlobalBounds().height / nrOfRows));
	this->whatRow = whatRow;
	this->nrOfCol = nrOfCol;
}


void Animator::updateAnimator(DeltaTime time)
{
	if (nrOfCol > 1) {
		timeToNextFrame += time.dt();
		while (timeToNextFrame >= timeBetween) {
			timeToNextFrame -= timeBetween;
			//animate
			rect.left += (rect.width) % ((int)(this->sprite->getTexture()->getSize().x));
			if (rect.width * nrOfCol <= rect.left) {
				rect.left = 0;
			}
			this->sprite->setTextureRect(rect);
		}
	}
}

void Animator::changeTimeBetween(float time)
{
	this->timeBetween = time;
}

void Animator::changeRow(int whatRow)
{
	this->whatRow = whatRow;
	this->rect.top = this->rect.height * whatRow;
}

void Animator::changeNrOfCols(int nrOfCols)
{
	this->nrOfCol = nrOfCols;
}

int Animator::getNrOfCol() const
{
	return this->nrOfCol;
}

int Animator::getNrOfRow() const
{
	return this->nrOfRows;
}

int Animator::getWhatRow() const
{
	return whatRow;
}

float Animator::getTimeBetween() const
{
	return timeBetween;
}
