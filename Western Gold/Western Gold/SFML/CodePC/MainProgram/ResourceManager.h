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

private:
	void cantLoad(LPCWSTR theerror);
	int windowWidth;
	int windowHeight;

	sf::SoundBuffer* ass;
	sf::Texture* tex;

	sf::Font* basicFont;
};

