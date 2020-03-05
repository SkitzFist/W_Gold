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
	delete level_test02;
	delete bullet;
	delete gunShot;
	delete enemy;
	delete AnimationTest;
	delete gold;
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
		cantLoad(L"Font");
	}
	AnimationTest = new sf::Texture();
	if (!AnimationTest->loadFromFile("../Textures/animationTest.png")) {
		cantLoad(L"animationtest");
	}
	gold = new sf::Texture();
	if (!gold->loadFromFile("../Textures/Gold.png")) {
		cantLoad(L"Gold");
	}
	gunShot = new sf::SoundBuffer();
	if (!gunShot->loadFromFile("../Sound/GunShot.wav")) {
		cantLoad(L"gun sound");
	}
	character = new sf::Texture();
	if (!character->loadFromFile("../Textures/hat.png")) {
		cantLoad(L"hat");
	}
	bullet = new sf::Texture();
	if (!bullet->loadFromFile("../Textures/Bullet.png")) {
		cantLoad(L"bullet");
	}
	ass = new sf::SoundBuffer();
	if (!ass->loadFromFile("../Sound/THX_Sound_Effect.wav")) {
		cantLoad(L"soundeffect");
	} 
	enemy = new sf::Texture();
	if (!enemy->loadFromFile("../Textures/hat2.png")) {
		cantLoad(L"enemy");
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

sf::Image* ResourceManager::getLevel_Test02()
{
	return level_test02;
}

sf::SoundBuffer* ResourceManager::getGunShot()
{
	return this->gunShot;
}

sf::Texture* ResourceManager::getEnemy()
{
	return enemy;
}

sf::SoundBuffer* ResourceManager::getass()
{
	return ass;
}

sf::Texture* ResourceManager::getAnimationTest()
{
	return this->AnimationTest;
}

sf::Texture* ResourceManager::getCharacter()
{
	return character;
}

sf::Texture* ResourceManager::getBullet()
{
	return this->bullet;
}

sf::Texture* ResourceManager::getGold()
{
	return this->gold;
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
	level_test02 = new sf::Image();
	if (!level_test02->loadFromFile("../Levels/level_test02.png")) {
		cantLoad(L"level_test02.png");
	}

}
