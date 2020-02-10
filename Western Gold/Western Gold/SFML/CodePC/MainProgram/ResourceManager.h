#pragma once
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "SoundManager.h"
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void windowSetup(int width, int height);
	int getWindowWidth() const;
	int getWindowHeight() const;

	void basicSetup();

	//debug
	sf::Font* getBasicFont();
	sf::SoundBuffer* getass();
	sf::Texture* gettex();

private:
	void cantLoad(LPCWSTR theerror);
	int windowWidth;
	int windowHeight;

	//debug
	sf::SoundBuffer* ass;
	sf::Texture* tex;

	sf::Font* basicFont;
};