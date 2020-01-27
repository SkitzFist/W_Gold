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
	delete line;
}

void Line::changeLine()
{
	delete this->line;
	this->line = new sf::Vertex[2]{
		sf::Vertex(sf::Vector2f(x1,y1)),
		sf::Vertex(sf::Vector2f(x2, y2))
	};
}

void Line::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->line, 2, sf::Lines);
}
