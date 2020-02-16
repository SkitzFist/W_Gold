#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "DeltaTime.h"

class Entity;
class Ray : public sf::Drawable{
private:
	float dir;
	sf::CircleShape pt;
	sf::CircleShape pos;
	Line line;
	void setRotation(float dir);
public:
	Ray(float dir);
	void updateRay(DeltaTime Time, Entity* entity);
	//get wall it should check collision with
	void getWall(Line line);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};