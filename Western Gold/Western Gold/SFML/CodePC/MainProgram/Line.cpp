#include "Line.h"

Line::Line(float x1, float y1, float x2, float y2)
{
	this->line = new sf::Vertex[2]{
		sf::Vertex(sf::Vector2f(x1,y1)),
		sf::Vertex(sf::Vector2f(x2, y2))
	};
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

Line::~Line()
{
	if (this->line != nullptr) {
		delete line;
	}
}

void Line::changeLine()
{
		delete this->line;
		this->line = new sf::Vertex[2]{
			sf::Vertex(sf::Vector2f(x1,y1)),
			sf::Vertex(sf::Vector2f(x2, y2))
		};
}

float Line::getLineX1() const
{
	return this->x1;
}

float Line::getLineX2() const
{
	return this->x2;
}

float Line::getLineY1() const
{
	return this->y1;
}

float Line::getLineY2() const
{
	return this->y2;
}

void Line::setLineX1(float x1)
{
	this->x1 = x1;
}

void Line::setLineX2(float x2)
{
	this->x2 = x2;
}

void Line::setLineY1(float y1)
{
	this->y1 = y1;
}

void Line::setLineY2(float y2)
{
	this->y2 = y2;
}

void Line::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->line, 2, sf::Lines);
}
