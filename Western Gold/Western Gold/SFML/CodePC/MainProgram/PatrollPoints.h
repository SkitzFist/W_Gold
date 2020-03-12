#pragma once
#include <SFML/Graphics.hpp>
class PatrollPoints
{
public:
	PatrollPoints(int size);
	~PatrollPoints();
	void add(sf::Vector2i point);
	sf::Vector2i getNextPoint();

private:
	sf::Vector2i* points;
	int size;
	int nrOf;
	int currentIndex;
};

