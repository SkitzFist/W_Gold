#pragma once
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void windowSetup(int width, int height);
	int getWindowWidth() const;
	int getWindowHeight() const;

	void basicSetup();

	sf::Font* getBasicFont();
	sf::SoundBuffer* getass();
	sf::Texture* gettex();

	//debug
	sf::Image* getLevel_test();
	sf::Texture* getTile_blue();
	sf::Texture* getTile_green();

private:
	void cantLoad(LPCWSTR theerror);
	int windowWidth;
	int windowHeight;

	sf::SoundBuffer* ass;
	sf::Texture* tex;

	sf::Font* basicFont;

	//debug
	sf::Image* level_test;
	sf::Texture* tile_blue;
	sf::Texture* tile_green;
};

