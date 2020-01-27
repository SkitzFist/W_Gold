#include "ResourceManager.h"
#include <iostream>


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
}

sf::Font * ResourceManager::getBasicFont()
{
	return basicFont;
}
