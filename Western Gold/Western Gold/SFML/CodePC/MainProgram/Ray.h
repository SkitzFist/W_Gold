#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "DeltaTime.h"
#include "GameObject.h"

class Entity;
class tile;
class Ray : public sf::Drawable{
private:
	float dir;
	Line line;
	void setRotation(float dir);
	bool check(float T, float R, float B, float L);
public:
	Ray(float dir = NULL);
	void updateRay(DeltaTime Time, Entity* entity);

	bool rayHitGameObject(GameObject* gameObj);
	bool rayHitTile(tile *Tile);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};