#include "InsideWindow.h"

bool insideWindow(GameObject *gameobj, sf::View* view)
{
	float L = view->getCenter().x - (view->getSize().x / 2);
	float T = view->getCenter().y - (view->getSize().y / 2);
	sf::FloatRect test(L, T, view->getSize().x, view->getSize().y);
	return gameobj->getBounds().intersects(test);
}

bool insideWindow(tile *Tile, sf::View* view)
{
	float L = view->getCenter().x - (view->getSize().x / 2);
	float T = view->getCenter().y - (view->getSize().y / 2);
	sf::FloatRect test(L, T, view->getSize().x, view->getSize().y);
	return Tile->getSprite()->getGlobalBounds().intersects(test);
}
