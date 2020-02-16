#include "Ray.h"
#include <iostream>
#include "Entity.h"

void Ray::setRotation(float dir)
{

}

Ray::Ray(float dir):
	line(0,0,0,0)
{
	this->dir = 0;
	this->pos.setFillColor(sf::Color::Yellow);
	this->pos.setPosition(0, 20);
	this->pos.setRadius(3);
}

void Ray::updateRay(DeltaTime Time, Entity* entity)
{
	const float PI = 3.14159f;

	dir = entity->getRotation();
	this->line.x1 = entity->getPosition().x;
	this->line.y1 = entity->getPosition().y;
	
	this->line.x2 = 700 * cos(dir * PI / 180 - 1.57) + line.x1;
	this->line.y2 = 700 * sin(dir * PI / 180 - 1.57) + line.y1;
	this->line.changeLine();
	
	
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
		//std::cout << "fuck" << std::endl;
	}
}

void Ray::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->line);
	target.draw(this->pos);
}
