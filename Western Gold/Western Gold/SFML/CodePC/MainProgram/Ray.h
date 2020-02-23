#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "DeltaTime.h"
#include "GameObject.h"


class Entity;
class tile;
class Player;
class Ray : public sf::Drawable{
private:
	float dir;
	Line line;
	void setRotation(float dir);
	bool check(float T, float R, float B, float L);
	void calcRotation();
public:
	Ray(float dir = NULL);
	virtual ~Ray();
	void updateRay(Entity* entity);
	void updateRay(Player *player, tile *Tile);
	bool rayHitGameObject(GameObject* gameObj);
	bool rayHitTile(tile *Tile);
	bool rayHitTile2(tile* Tile);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};