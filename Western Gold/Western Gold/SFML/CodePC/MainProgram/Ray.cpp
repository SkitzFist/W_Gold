#include "Ray.h"
#include <iostream>
#include "GetDistance.h"

#include "Player.h"
#include "Tile.h"

void Ray::setRotation(float dir)
{
	this->dir = dir;
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

void Ray::calcRotation()
{
	this->dir = (atan2f((line.y1 - line.y2), (line.x1- line.x2)) * 180.0000) / 3.1416 + 90;
	dir = ((float)((int)(dir * 10) % 3600)) / 10;
	while (dir < 0) {
		dir = 360 - dir;
	}
}



Ray::Ray(float dir):
	line(0,0,0,0)
{
	this->dir = 0;
}

Ray::~Ray()
{
}

void Ray::updateRay(Entity* entity)
{
	const float PI = 3.14159f;

	dir = entity->getRotation();
	this->line.x1 = entity->getPosition().x;
	this->line.y1 = entity->getPosition().y;
	
	this->line.x2 = (float)(700 * cos(dir * PI / 180 - 1.57) + line.x1);
	this->line.y2 = (float)(700 * sin(dir * PI / 180 - 1.57) + line.y1);
	this->line.changeLine();
	
	
}

void Ray::updateRay(Player *player, tile *Tile)
{

	this->line.x1 = player->getPosition().x;
	this->line.y1 = player->getPosition().y;

	this->line.x2 = Tile->getSprite()->getPosition().x;
	this->line.y2 = Tile->getSprite()->getPosition().y;


	calcRotation();
	this->line.changeLine();
}

bool Ray::rayHitGameObject(GameObject* gameObj)
{
	bool theReturn = false;
	std::cout << dir << std::endl;

	if (dir > 270 && (gameObj->getTop() < this->line.y1)) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (dir > 180 && gameObj->getBot() >= this->line.y1 ) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (dir > 90 && (gameObj->getBot() >= this->line.y1) ) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (gameObj->getTop() <= this->line.y1 ) {
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

	if (dir > 270 && (tileTop < this->line.y1)) {
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}
	else if (dir > 180 && tileBot >= this->line.y1 ) {
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}
	else if (dir > 90 && (tileBot >= this->line.y1) ) {
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}
	else if(dir >= 0 && tileTop <= this->line.y1){
		theReturn = check(tileTop, tileRight, tileBot, tileLeft);
	}
	else {
		std::cout << dir << std::endl;
	}

	return theReturn;
}


void Ray::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->line);
}
