#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "DeltaTime.h"
#include "GameObject.h"


class Entity;
class tile;
class Player;
class Enemy;
class Ray : public sf::Drawable{
private:
	float dir;
	Line line;
	float rotationOffset;
	void setRotation(float dir);
	bool check(float T, float R, float B, float L);
	void calcRotation();
public:
	Ray(float dir = NULL);
	virtual ~Ray();
	void setRotationOffset(float offset, Entity* entity = nullptr);
	float getRotationOffset()const;
	void updateRay(Entity* entity);
	void updateRay(Player *player, tile *Tile);
	void updateRay(GameObject *gameObj1, GameObject *gameObj2);
	bool rayHitGameObject(GameObject* gameObj);
	bool rayHitTile(tile *Tile);
	bool rayHitTile2(tile* Tile);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};