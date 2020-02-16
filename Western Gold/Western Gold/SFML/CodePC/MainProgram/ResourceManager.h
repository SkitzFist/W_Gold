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
#pragma endregion

	//debug
	
	sf::SoundBuffer* getass();
	sf::Texture* gettex();

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
#pragma endregion

#pragma region Sounds

#pragma endregion

	//debug
	sf::SoundBuffer* ass;
	sf::Texture* tex;


private:
	void basicSetup();
	void cantLoad(LPCWSTR theerror);
	//debug
	void debugSetup();
};