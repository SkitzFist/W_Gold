#pragma once
#include "GameObject.h"
#include "Tile.h"

bool insideWindow(GameObject *gameobj, sf::View* view);
bool insideWindow(tile *Tile, sf::View* view);