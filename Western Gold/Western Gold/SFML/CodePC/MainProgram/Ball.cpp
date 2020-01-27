#include "Ball.h"


Ball::Ball(int x, float radius, sf::Color color)
{
	isFalling = false;
	velX = 0;
	velY = 0;
	circle.setRadius(radius);
	circle.setFillColor(color);
	circle.setPosition(x / 2 - radius , 0 + radius);
}

Ball::~Ball()
{
}

void Ball::input(const sf::Event & event)
{
	if (!isFalling) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Right) {
				velX = speed;
			}
			else if (event.key.code == sf::Keyboard::Left) {
				velX = -speed;
			}
			else if (event.key.code == sf::Keyboard::Space) {
				velY = speed + speed;
				isFalling = true;
			}
		}
		else if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Right && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				velX = 0;
			}
			else if (event.key.code == sf::Keyboard::Left && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				velX = 0;
			}
		}
	}
	

}

void Ball::update(int width)
{
	circle.move(velX, velY);

	if (circle.getPosition().x < 0.f) {
		circle.setPosition(0.f, circle.getPosition().y);
	}
	else if (circle.getPosition().x > width - circle.getRadius() *2 ) {
		circle.setPosition(width - circle.getRadius() *2, circle.getPosition().y);
	}
}

void Ball::reset(int x)
{
	velY = 0;
	velX = 0;
	circle.setPosition(x / 2 - circle.getRadius(), 0 + circle.getRadius());
	isFalling = false;
}

sf::Vector2f Ball::getPos() const
{
	return circle.getPosition();
}

sf::FloatRect Ball::getBounds() const
{
	return circle.getGlobalBounds();
}

float Ball::getRadius() const
{
	return circle.getRadius();
}

void Ball::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(circle, states);
}
