#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
class Basket : public sf::Drawable
{
public:
	Basket(float width, float height, float x = 400.f, sf::Color color = sf::Color::Magenta);
	~Basket();
	bool hitBy(const Ball &ball);
	void reset(int x);
	void increaseScore();
	int getScore() const;

private:
	int score;
	sf::RectangleShape rect;
	const float Y_POS = 560;

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};

