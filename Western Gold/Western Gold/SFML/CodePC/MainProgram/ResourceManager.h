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

	//debug
	sf::Image* getLevel_test();
	sf::Texture* getTile_blue();
	sf::Texture* getTile_green();

private:
	int windowWidth;
	int windowHeight;

	sf::Font* basicFont;

	//debug
	sf::Image* level_test;
	sf::Texture* tile_blue;
	sf::Texture* tile_green;
};

