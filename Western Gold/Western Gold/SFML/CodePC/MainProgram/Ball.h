#pragma once
#include <SFML/Graphics.hpp>
class Ball : public sf::Drawable
{
public:
	Ball(int x,float radius = 15.f, sf::Color color = sf::Color::Blue);
	~Ball();
	void input(const sf::Event &event);
	void update(int width);
	void reset(int width);
	sf::Vector2f getPos() const;
	sf::FloatRect getBounds()const;
	float getRadius()const;
	// Inherited via Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	sf::CircleShape circle;
	const float speed = 3.f;
	float velX;
	float velY;

	bool isFalling;
private:

};

