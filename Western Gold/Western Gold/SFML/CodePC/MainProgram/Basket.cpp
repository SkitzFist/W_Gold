#include "Basket.h"



Basket::Basket(float width, float height, float x, sf::Color color):
	rect(sf::Vector2f(width, height))
{
	rect.setFillColor(color);
	rect.setPosition(x, Y_POS);
	score = 0;
}


Basket::~Basket()
{
}

bool Basket::hitBy(const Ball & ball)
{
	bool hasCollided = false;

	if(ball.getPos().x > rect.getPosition().x 
		&&(ball.getPos().x + ball.getRadius()) < (rect.getPosition().x + rect.getSize().x)
		&& (ball.getPos().y + ball.getRadius()) > (rect.getPosition().y)
		&& ball.getPos().y < (rect.getPosition().y + rect.getSize().y)) {
		hasCollided = true;
	}

	return hasCollided;
}

void Basket::reset(int x)
{
	rect.setPosition(rand() % x , Y_POS);
	if (rect.getPosition().x < 0) {
		rect.setPosition(0 + rect.getSize().x, Y_POS);
	}
	else if (rect.getPosition().x > x - rect.getPosition().x) {
		rect.setPosition(x - rect.getPosition().x, Y_POS);
	}

}

void Basket::increaseScore()
{
	++score;
}

int Basket::getScore() const
{
	return this->score;
}

void Basket::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect, states);
}
