#include "ResourceManager.h"
#include <iostream>


ResourceManager::ResourceManager()
{
	//config
	//setup
	this->view = nullptr;
	loadFont();
	//debug
}


ResourceManager::~ResourceManager()
{
	//sound
	delete klingSound;
	delete gunShot;
	//texture
	delete Mouse;
	delete enemy;
	delete gold;
	delete cylinder;
	delete UIBullet;
	delete character;
	delete tile_sand;
	delete tile_floor;
	delete tile_wall;
	delete level_01;
	delete bullet;
	//fonts
	delete basicFont;
	delete WesternFont;
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

sf::View* ResourceManager::getView() const
{
	return this->view;
}

void ResourceManager::setView(sf::View* camera)
{
	this->view = camera;
}

void ResourceManager::loadFont()
{
	basicFont = new sf::Font();
	if (!basicFont->loadFromFile("../Fonts/segoui.ttf")) {
		cantLoad(L"Font");
	}
	WesternFont = new sf::Font();
	if (!WesternFont->loadFromFile("../Fonts/Western_Bang_Bang.otf")) {
		cantLoad(L"westerFont");
	}
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

void ResourceManager::loadSprites()
{
	
	UIBullet = new sf::Texture();
	if (!UIBullet->loadFromFile("../Textures/UIBullet.png")) {
		cantLoad(L"UI Bullet");
	}
	cylinder = new sf::Texture();
	if (!cylinder->loadFromFile("../Textures/cylinder.png")) {
		cantLoad(L"cylinder");
	}
	gold = new sf::Texture();
	if (!gold->loadFromFile("../Textures/Gold.png")) {
		cantLoad(L"Gold");
	}
	character = new sf::Texture();
	if (!character->loadFromFile("../Textures/player.png")) {
		cantLoad(L"player");
	}
	bullet = new sf::Texture();
	if (!bullet->loadFromFile("../Textures/Bullet.png")) {
		cantLoad(L"bullet");
	}
	enemy = new sf::Texture();
	if (!enemy->loadFromFile("../Textures/hat2.png")) {
		cantLoad(L"enemy");
	}
}

void ResourceManager::loadSounds()
{
	gunShot = new sf::SoundBuffer();
	if (!gunShot->loadFromFile("../Sound/GunShot.wav")) {
		cantLoad(L"gun sound");
	}
	klingSound = new sf::SoundBuffer();
	if (!klingSound->loadFromFile("../Sound/klingSound.wav")) {
		cantLoad(L"klingSound");
	}
}

void ResourceManager::loadMouse()
{
	Mouse = new sf::Texture();
	if (!Mouse->loadFromFile("../Textures/Mouse.png")) {
		cantLoad(L"mouse");
	}
}

void ResourceManager::setDeltaTime(DeltaTime& dt)
{
	this->dt = &dt;

}

int ResourceManager::getWindowWidth() const
{
	return windowWidth;
}

int ResourceManager::getWindowHeight() const
{
	return windowHeight;
}

sf::Font* ResourceManager::getBasicFont()
{
	return basicFont;
}

sf::Font* ResourceManager::getWesternFont()
{
	return WesternFont;
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

sf::Image* ResourceManager::getLevel_01()
{
	return level_01;
}

sf::SoundBuffer* ResourceManager::getGunShot()
{
	return this->gunShot;
}

sf::SoundBuffer* ResourceManager::getKlingSound()
{
	return klingSound;
}

DeltaTime* ResourceManager::getDt() const
{
	return this->dt;
}

sf::Texture* ResourceManager::getEnemy()
{
	return enemy;
}


sf::Texture* ResourceManager::getCharacter()
{
	return character;
}

sf::Texture* ResourceManager::getBullet()
{
	return this->bullet;
}

sf::Texture* ResourceManager::getUIBullet()
{
	return UIBullet;
}

sf::Texture* ResourceManager::getGold()
{
	return this->gold;
}

sf::Texture* ResourceManager::getCylinder()
{
	return this->cylinder;
}

sf::Texture* ResourceManager::getMouse()
{
	return Mouse;
}

void ResourceManager::cantLoad(LPCWSTR theerror)
{
	MessageBox(nullptr, theerror, L"ERROR", MB_ICONWARNING | MB_OK);
}
