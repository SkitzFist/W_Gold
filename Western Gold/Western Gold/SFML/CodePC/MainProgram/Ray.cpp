#include "Ray.h"
#include <iostream>

void Ray::setRotation(float dir)
{

}

Ray::Ray():
	line(0,0,0,0)
{
	this->dir = 0;
	this->pos.setFillColor(sf::Color::Yellow);
	this->pos.setPosition(0, 20);
	this->pos.setRadius(3);
}

void Ray::updateRay(DeltaTime &Time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir += static_cast<float>( 0.5f * Time.dt() * 100.f);
		std::cout << Time.dt() << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dir -= 0.5f;
	}
		if (dir > 360) {
			dir = dir - 360;
		}
		if (dir < 0) {
			dir += 360;
		}
	
}

void Ray::getWall(Line line)
{
	float radias = (float)((3.14159265359 / 180)*(this->dir - 90));
	 
	float x1 = 200;
	float y1 = 100;
	float x2 = cos(radias) * 200 + x1;
	float y2 = sin(radias) * 200 + y1;

	this->line.x1 = x1;
	this->line.y1 = y1;
	this->line.x2 = x2;
	this->line.y2 = y2;
	this->line.changeLine();
	

	
	float den = (line.x1 - line.x2)*(y1 - y2) - (line.y1 - line.y2)*(x1 - x2);
	if (den != 0) {
		float t = ((line.x1 - x1)*(y1 - y2) - (line.y1 - y1)*(x1 - x2)) / den;
		float u = -((line.x1 - line.x2)*(line.y1 - y1) - (line.y1 - line.y2)*(line.x1 - x1)) / den;
		if (t > 0 && t < 1 && u > 0) {
			std::cout << "hit" << std::endl;
			this->line.x2 = (x1+u*(x2-x1));
			this->line.y2 = (y1+u*(y2-y1));
			this->line.changeLine();
		}
	}
	else {
		std::cout << den << std::endl;
	}
}

void Ray::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->line);
	target.draw(this->pos);
}
