#pragma once
#include <SFML/Graphics.hpp>
//debug
#include <string>
class PatrollPoints
{
public:
	PatrollPoints(int size);
	~PatrollPoints();
	void add(sf::Vector2i point);
	sf::Vector2i getNextPoint();
	sf::Vector2i* getPoints() const;

private:
	sf::Vector2i* points;
	int size;
	int nrOf;
	int currentIndex;
};

