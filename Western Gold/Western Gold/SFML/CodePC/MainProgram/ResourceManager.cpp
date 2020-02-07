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
	delete tex;
	delete ass;
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
	ass = new sf::SoundBuffer();
	tex = new sf::Texture();
	if (!tex->loadFromFile("../Textures/Untitled.png")) {
		cantLoad(L"tex");
	}
	if (!ass->loadFromFile("../Sound/THX_Sound_Effect.wav")) {
		cantLoad(L"ass");
	}
	if (!basicFont->loadFromFile("../Fonts/segoui.ttf")) {
		//std::cerr << "Could not load font segoui.ttf" << std::endl;
		cantLoad(L"Font");
	}
}

sf::Font* ResourceManager::getBasicFont()
{
	return basicFont;
}

sf::SoundBuffer* ResourceManager::getass()
{
	return ass;
}

sf::Texture* ResourceManager::gettex()
{
	return tex;
}

void ResourceManager::cantLoad(LPCWSTR theerror)
{
	MessageBox(nullptr, theerror, L"ERROR", MB_ICONWARNING | MB_OK);
}