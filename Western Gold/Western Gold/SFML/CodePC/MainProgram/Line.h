#pragma once
#include <SFML/Graphics.hpp>

class Line : public sf::Drawable{
private:
	sf::Vertex* line;
public:
	Line(float x1, float y1, float x2, float y2);
	virtual ~Line();
	//update the line
	void changeLine();
	float x1, x2, y1, y2;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};