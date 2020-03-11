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
	delete tile_sand;
	delete tile_floor;
	delete tile_wall;
	delete level_test;
	delete level_test02;
	delete level_test03;
	delete level_01;
	delete bullet;
	delete gunShot;
	delete enemy;
	delete AnimationTest;
	delete gold;
	delete cylinder;
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

void ResourceManager::loadTilesAndLevels()
{
	tile_sand = new sf::Texture();
	if (!(tile_sand->loadFromFile("../Textures/tile_sand.png"))) {
		cantLoad(L"can't load: tile_sand.png");
	}
	tile_floor = new sf::Texture();
	if (!(tile_floor->loadFromFile("../Textures/tile_floor.png"))) {
		cantLoad(L"can't load: tile_floor.png");
	}
	tile_wall = new sf::Texture();
	if (!(tile_wall->loadFromFile("../Textures/tile_wall.png"))) {
		cantLoad(L"can't load: tile_wall.png");
	}
	level_01 = new sf::Image();
	if (!(level_01->loadFromFile("../Levels/level_01.png"))) {
		cantLoad(L"can't load: level_01.png");
	}
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
	cylinder = new sf::Texture();
	if (!cylinder->loadFromFile("../Textures/cylinder.png")) {
		cantLoad(L"cylinder");
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

sf::Texture* ResourceManager::getTile_floor()
{
	return tile_floor;
}

sf::Texture* ResourceManager::getTile_sand()
{
	return tile_sand;
}

sf::Texture* ResourceManager::getTile_wall()
{
	return tile_wall;
}

sf::Image* ResourceManager::getLevel_Test()
{
	return level_test;
}

sf::Image* ResourceManager::getLevel_Test02()
{
	return level_test02;
}

sf::Image* ResourceManager::getLevel_Test03()
{
	return level_test03;
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

sf::Texture* ResourceManager::getCylinder()
{
	return this->cylinder;
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
	level_test03 = new sf::Image();
	if (!level_test03->loadFromFile("../Levels/level_test03.png")) {
		cantLoad(L"level_test03.png");
	}
}
