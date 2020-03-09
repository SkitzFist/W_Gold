#pragma once
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "SoundManager.h"
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void windowSetup(sf::RenderWindow* window);
	int getWindowWidth() const;
	int getWindowHeight() const;
	sf::RenderWindow* getWindow();

#pragma region Fonts
	sf::Font* getBasicFont();
#pragma endregion

#pragma region Tiles
	sf::Texture* getTile_White();
	sf::Texture* getTile_Black();
	sf::Texture* getTile_Ok();
#pragma endregion

#pragma region Levels
	sf::Image* getLevel_Test();
	sf::Image* getLevel_Test02();
	sf::Image* getLevel_Test03();
#pragma endregion

#pragma region objects
	sf::Texture* getCharacter();
	sf::Texture* getBullet();
	sf::Texture* getGold();
#pragma endregion

#pragma region Sound
	sf::SoundBuffer* getGunShot();
#pragma endregion
	//debug
	sf::Texture* getEnemy();
	sf::SoundBuffer* getass();
	sf::Texture* getAnimationTest();
	

private:
	int windowWidth;
	int windowHeight;
	sf::RenderWindow* window;

#pragma region Fonts
	sf::Font* basicFont;
#pragma endregion

#pragma region Tiles
	sf::Texture* tile_white;
	sf::Texture* tile_black;
	sf::Texture* tile_ok;
#pragma endregion 

#pragma region Levels
	sf::Image* level_test;
	sf::Image* level_test02;
	sf::Image* level_test03;
#pragma endregion

#pragma region objects
	sf::Texture* character;
	sf::Texture* bullet;
	sf::Texture* gold;
#pragma endregion

#pragma region Sound
	sf::SoundBuffer* gunShot;
#pragma endregion

	//debug
	sf::SoundBuffer* ass;
	sf::Texture* enemy;
	sf::Texture* AnimationTest;


private:
	void basicSetup();
	void cantLoad(LPCWSTR theerror);
	//debug
	void debugSetup();
};