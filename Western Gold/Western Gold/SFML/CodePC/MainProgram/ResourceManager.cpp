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
	delete character;
	delete ass;
	delete tile_black;
	delete tile_white;
	delete tile_ok;
	delete level_test;
	
}

void ResourceManager::windowSetup(sf::RenderWindow* window)
{
	this->window = window;
	windowWidth = window->getSize().x;
	windowHeight = window->getSize().y;
}

sf::RenderWindow* ResourceManager::getWindow()
{
	return window;
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
		//std::cerr << "Could not load font segoui.ttf" << std::endl;
		cantLoad(L"Font");
	}


	character = new sf::Texture();
	if (!character->loadFromFile("../Textures/hat.png")) {
		cantLoad(L"tex");
	}

	ass = new sf::SoundBuffer();
	if (!ass->loadFromFile("../Sound/THX_Sound_Effect.wav")) {
		cantLoad(L"ass");
	}


	debugSetup();
}

sf::Font* ResourceManager::getBasicFont()
{
	return basicFont;
}

sf::Texture* ResourceManager::getTile_White()
{
	return tile_white;
}

sf::Texture* ResourceManager::getTile_Black()
{
	return tile_black;
}

sf::Texture* ResourceManager::getTile_Ok()
{
	return tile_ok;
}

sf::Image* ResourceManager::getLevel_Test()
{
	return level_test;
}

sf::SoundBuffer* ResourceManager::getass()
{
	return ass;
}

sf::Texture* ResourceManager::getCharacter()
{
	return character;
}

sf::Texture* ResourceManager::getBullet()
{
	return this->bullet;
}

void ResourceManager::cantLoad(LPCWSTR theerror)
{
	MessageBox(nullptr, theerror, L"ERROR", MB_ICONWARNING | MB_OK);
}

void ResourceManager::debugSetup()
{
	tile_white = new sf::Texture();
	if (!tile_white->loadFromFile("../Textures/tile_white.png")) {
		cantLoad(L"white_tile.png");
	}
	tile_black = new sf::Texture();
	if (!tile_black->loadFromFile("../Textures/tile_black.png")) {
		cantLoad(L"black_tile.png");
	}
	tile_ok = new sf::Texture();
	if (!tile_ok->loadFromFile("../Textures/tile_ok.png")) {
		cantLoad(L"tile_ok.png");
	}
	level_test = new sf::Image();
	if (!level_test->loadFromFile("../Levels/level_test.png")) {
		cantLoad(L"level_test.png");
	}

}
