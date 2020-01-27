#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

class Obstacle : public sf::Drawable
{
public:
	Obstacle(float width, float height, float x = -100,float y = -100, sf::Color = sf::Color::Green);
	~Obstacle();
	sf::FloatRect getBounds() const;
	bool hitBy(const Ball &ball);

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
private:
	sf::RectangleShape rect;
};

