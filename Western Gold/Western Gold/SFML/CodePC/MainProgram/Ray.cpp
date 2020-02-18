#include "Ray.h"
#include <iostream>

#include "Entity.h"
#include "Tile.h"

void Ray::setRotation(float dir)
{

}

bool Ray::check(float T, float R, float B, float L)
{
	float k = (float)((this->line.y1 - this->line.y2) / (this->line.x1 - this->line.x2));
	float m = (float)(this->line.y1 - (k * this->line.x1));
	bool theReturn = false;
	if ((B - m) / k >= L && (B - m) / k <= R) {
		theReturn = true;
	}
	if ((T - m) / k >= L && (T - m) / k <= R) {
		theReturn = true;
		this->line.y2 = T;
	}
	if ((R * k + m) <= B && (R * k + m) >= T) {
		theReturn = true;
		this->line.x2 = R;
	}
	if ((L * k + m) <= B && (L * k + m) >= T) {
		theReturn = true;
		this->line.x2 = L;
	}
	


	return theReturn;
}

Ray::Ray(float dir):
	line(0,0,0,0)
{
	this->dir = 0;
}

void Ray::updateRay(DeltaTime Time, Entity* entity)
{
	const float PI = 3.14159f;

	dir = entity->getRotation();
	this->line.x1 = entity->getPosition().x;
	this->line.y1 = entity->getPosition().y;
	
	this->line.x2 = (float)(700 * cos(dir * PI / 180 - 1.57) + line.x1);
	this->line.y2 = (float)(700 * sin(dir * PI / 180 - 1.57) + line.y1);
	this->line.changeLine();
	
	
}


bool Ray::rayHitGameObject(GameObject* gameObj)
{
	bool theReturn = false;

	if (dir > 270 && (gameObj->getBot() < this->line.y1) && gameObj->getRight() < this->line.x1) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (dir > 180 && gameObj->getTop() >= this->line.y1 && gameObj->getRight() <= this->line.x1) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (dir > 90 && (gameObj->getBot() >= this->line.y1) && gameObj->getLeft() >= this->line.x1) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (gameObj->getBot() <= this->line.y1 && gameObj->getLeft() >= this->line.x1) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}

	return theReturn;
}

bool Ray::rayHitTile(tile *Tile)
{
	bool theReturn = false;
	
	float tileBot = Tile->getSprite()->getGlobalBounds().top + Tile->getSprite()->getGlobalBounds().height;
	float tileTop = Tile->getSprite()->getGlobalBounds().top;
	float tileLeft = Tile->getSprite()->getGlobalBounds().left;
	float tileRight = Tile->getSprite()->getGlobalBounds().left + Tile->getSprite()->getGlobalBounds().width;

	if (dir > 270 && (tileBot < this->line.y1) && tileRight < this->line.x1) {
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}
	else if (dir > 180 && tileTop >= this->line.y1 && tileRight <= this->line.x1) {
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}
	else if (dir > 90 && (tileBot >= this->line.y1) && tileLeft >= this->line.x1) {
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}
	else if(tileBot <= this->line.y1 && tileLeft >= this->line.x1){
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}


	return theReturn;
}

void Ray::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->line);
}
