#include "Obstacle.h"


Obstacle::Obstacle(float width, float height, float x, float y, sf::Color color):
	rect(sf::Vector2f(width,height))
{
	this->rect.setFillColor(color);
	this->rect.setPosition(x, y);
}

Obstacle::~Obstacle()
{
}

sf::FloatRect Obstacle::getBounds() const
{
	return rect.getGlobalBounds();
}

bool Obstacle::hitBy(const Ball & ball)
{
	return this->rect.getGlobalBounds().intersects(ball.getBounds());
}

void Obstacle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect, states);
}
