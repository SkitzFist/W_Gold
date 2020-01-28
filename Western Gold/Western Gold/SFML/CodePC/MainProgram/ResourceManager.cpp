#include "ResourceManager.h"
#include <iostream>

/* Gör ett test med git för o se vad som händer om vi har lagt till olika resurser
	Blir det en konflikt eller inte?*/

ResourceManager::ResourceManager()
{
	//config

	//setup
	basicSetup();

	//debug
}


ResourceManager::~ResourceManager()
{
	delete basicFont;
	
	//debug
	delete level_test;
	delete tile_blue;
	delete tile_green;
}

void ResourceManager::windowSetup(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
}

int ResourceManager::getWindowWidth() const
{
	return windowWidth;
}

int ResourceManager::getWindowHeight() const
{
	return windowHeight;
}

void ResourceManager::basicSetup()
{
	basicFont = new sf::Font();
	if (!basicFont->loadFromFile("../Fonts/segoui.ttf")) {
		std::cerr << "Could not load font segoui.ttf" << std::endl;
	}

	//debug
	level_test = new sf::Image();
	if (!level_test->loadFromFile("../Levels/level_test.png")) {
		std::cerr << "Could not load level_test.png" << std::endl;
	}
	tile_blue = new sf::Texture();
	if (!tile_blue->loadFromFile("../Sprites/tile_blue.png")) {
		std::cerr << "Could not load tile_blue.png" << std::endl;
	}
	tile_green = new sf::Texture();
	if (!tile_green->loadFromFile("../Sprites/tile_green.png")) {
		std::cerr << "Could not load tile_green.png" << std::endl;
	}
}

sf::Font * ResourceManager::getBasicFont()
{
	return basicFont;
}

sf::Image* ResourceManager::getLevel_test()
{
	return level_test;
}

sf::Texture* ResourceManager::getTile_blue()
{
	return tile_blue;
}

sf::Texture* ResourceManager::getTile_green()
{
	return tile_green;
}
