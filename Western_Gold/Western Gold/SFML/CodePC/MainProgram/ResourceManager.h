#pragma once
#include <SFML/Graphics.hpp>
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

private:
	int windowWidth;
	int windowHeight;

	sf::Font* basicFont;
};

