#include "Ray.h"
#include <iostream>
#include "Player.h"
#include "Tile.h"
#include "Enemy.h"

void Ray::setRotation(float dir)
{
	this->dir = dir;
}

bool Ray::check(float T, float R, float B, float L)
{
	float k = (float)((this->line.getLineY1() - this->line.getLineY2()) / (this->line.getLineX1() - this->line.getLineX2()));
	float m = (float)(this->line.getLineY1() - (k * this->line.getLineX1()));
	bool theReturn = false;
	if ((B - m) / k >= L && (B - m) / k <= R) {
		theReturn = true;
	}
	if ((T - m) / k >= L && (T - m) / k <= R) {
		theReturn = true;
	}
	if ((R * k + m) <= B && (R * k + m) >= T) {
		theReturn = true;
	}
	if ((L * k + m) <= B && (L * k + m) >= T) {
		theReturn = true;
	}
	


	return theReturn;
}

void Ray::calcRotation()
{
	this->dir = (atan2f((line.getLineY1() - line.getLineY2()), (line.getLineX1()- line.getLineX2())) * 180.0f) / 3.1416f + 90.0f;
	dir = ((float)((int)(dir * 10) % 3600)) / 10;
	while (dir < 0) {
		dir = 360 - dir;
	}
}



Ray::Ray(float dir) :
	line(0, 0, 0, 0)
{
	this->dir = 0;
}

Ray::~Ray()
{
}

void Ray::updateRay(Entity* entity)
{
	const float PI = 3.14159f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		std::cout << "stop" << std::endl;
	}
	dir = entity->getRotation();
	this->line.setLineX1(entity->getPosition().x);
	this->line.setLineY1(entity->getPosition().y);

	this->line.setLineX2((float)(700 * cos(dir * PI / 180 - 1.57) + line.getLineX1()));
	this->line.setLineY2((float)(700 * sin(dir * PI / 180 - 1.57) + line.getLineY1()));
	this->line.changeLine();


}

void Ray::updateRay(Player* player, tile* Tile)
{

	this->line.setLineX1(player->getPosition().x);
	this->line.setLineY1(player->getPosition().y);

	this->line.setLineX2(Tile->getSprite()->getPosition().x);
	this->line.setLineY2(Tile->getSprite()->getPosition().y);


	//calcRotation();
	this->line.changeLine();
}

bool Ray::rayHitGameObject(GameObject* gameObj)
{
	bool theReturn = false;
	//why cant I do this???
	std::cout << dir << std::endl;
	if (dir > 270 && (gameObj->getTop() < this->line.getLineY1())) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (dir > 180 && dir < 270 && (gameObj->getBot() >= this->line.getLineY1())) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (dir > 90 && dir < 180 && (gameObj->getBot() >= this->line.getLineY1())) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	else if (dir >= 0 && dir < 90 && gameObj->getTop() <= this->line.getLineY1()) {
		theReturn = check(gameObj->getTop(), gameObj->getRight(), gameObj->getBot(), gameObj->getLeft());
	}
	return theReturn;
}

bool Ray::rayHitTile(tile* Tile)
{
	bool theReturn = false;
	float B = Tile->getSprite()->getGlobalBounds().top + Tile->getSprite()->getGlobalBounds().height;
	float T = Tile->getSprite()->getGlobalBounds().top;
	float L = Tile->getSprite()->getGlobalBounds().left;
	float R = Tile->getSprite()->getGlobalBounds().left + Tile->getSprite()->getGlobalBounds().width;

	float k = (float)((this->line.getLineY1() - this->line.getLineY2()) / (this->line.getLineX1() - this->line.getLineX2()));
	float m = (float)(this->line.getLineY1() - (k * this->line.getLineX1()));

	if ((B - m) / k >= L && (B - m) / k <= R) {
		if ((line.getLineY2() < B) && (line.getLineY1() > B)) {
			theReturn = true;
		}
	}
	if ((T - m) / k >= L && (T - m) / k <= R) {
		if (line.getLineY2() > T&& line.getLineY1() < T)
		{
			theReturn = true;
		}
	}
	if ((R * k + m) <= B && (R * k + m) >= T && (line.getLineX2() < R && line.getLineX1() > R)) {
		if (line.getLineX2() < R && line.getLineX1() > R) {
			theReturn = true;
		}
	}
	if ((L * k + m) <= B && (L * k + m) >= T) {
		if (line.getLineX2() > L&& line.getLineX1() < L) {
			theReturn = true;
		}
	}
	return theReturn;
}

bool Ray::rayHitTile2(tile* Tile)
{
	bool theReturn = false;
	float B = Tile->getSprite()->getGlobalBounds().top + Tile->getSprite()->getGlobalBounds().height;
	float T = Tile->getSprite()->getGlobalBounds().top;
	float L = Tile->getSprite()->getGlobalBounds().left;
	float R = Tile->getSprite()->getGlobalBounds().left + Tile->getSprite()->getGlobalBounds().width;
	std::cout << dir << std::endl;
	if (dir > 270 && (T < this->line.getLineY1())) {
		theReturn = check(T, R, B, L);
	}
	else if (dir > 180 && dir < 270 && (B >= this->line.getLineY1())) {
		theReturn = check(T, R, B, L);
	}
	else if (dir > 90 && dir < 180 && (B >= this->line.getLineY1())) {
		theReturn = check(T, R, B, L);
	}
	else if (dir >= 0 && dir < 90 && T <= this->line.getLineY1()) {
		theReturn = check(T, R, B, L);
	}
	return theReturn;
}

void Ray::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->line);
}
