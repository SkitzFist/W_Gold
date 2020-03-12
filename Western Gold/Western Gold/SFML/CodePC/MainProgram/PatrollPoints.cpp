#include "PatrollPoints.h"

//debug
#include <iostream>

PatrollPoints::PatrollPoints(int size)
{
	this->size = size;
	nrOf = 0;
	currentIndex = 0;
	points = new sf::Vector2i[size]{ {0,0} };
}

PatrollPoints::~PatrollPoints()
{
	delete[] points;
}

void PatrollPoints::add(sf::Vector2i point)
{
	if (!(nrOf >= size)) {
		points[nrOf++] = point;
	}	
}

sf::Vector2i PatrollPoints::getNextPoint()
{
	currentIndex = (currentIndex + 1) % size;
	std::cout << currentIndex << std::endl;
	return points[currentIndex];
}

void PatrollPoints::print()
{
	for (int i = 0; i < size; ++i) {
		std::cout << points[i].x << "." << points[i].y << std::endl;
	}
}
