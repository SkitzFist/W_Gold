#pragma once
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "SoundManager.h"
#include "DeltaTime.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void windowSetup(sf::RenderWindow* window);
	int getWindowWidth() const;
	int getWindowHeight() const;
	sf::RenderWindow* getWindow();
	sf::View* getView()const;
	void setView(sf::View* camera);
	void loadFont();
	void loadTilesAndLevels();
	void loadSprites();
	void loadSounds();
	void loadMouse();
	void setDeltaTime(DeltaTime& dt);

#pragma region Fonts
	sf::Font* getBasicFont();
	sf::Font* getWesternFont();
#pragma endregion

#pragma region Tiles
	sf::Texture* getTile_floor();
	sf::Texture* getTile_sand();
	sf::Texture* getTile_wall();
#pragma endregion

#pragma region Levels
	sf::Image* getLevel_01(); 
#pragma endregion

#pragma region objects + UI
	sf::Texture* getCharacter();
	sf::Texture* getBullet();
	sf::Texture* getUIBullet();
	sf::Texture* getGold();
	sf::Texture* getCylinder();
#pragma endregion

	sf::Texture* getMouse();

#pragma region Sound
	sf::SoundBuffer* getGunShot();
	sf::SoundBuffer* getKlingSound();
#pragma endregion
	sf::Texture* getEnemy();
	
	DeltaTime* getDt() const;

private:
	DeltaTime* dt;
	int windowWidth;
	int windowHeight;
	sf::RenderWindow* window;
	sf::View *view;

#pragma region Fonts
	sf::Font* basicFont;
	sf::Font* WesternFont;
#pragma endregion

#pragma region Tiles
	sf::Texture* tile_sand;
	sf::Texture* tile_floor;
	sf::Texture* tile_wall;
#pragma endregion 

#pragma region Levels
	sf::Image* level_01;
#pragma endregion

#pragma region objects + UI
	sf::Texture* character;
	sf::Texture* bullet;
	sf::Texture* UIBullet;
	sf::Texture* gold;
	sf::Texture* cylinder;
#pragma endregion

	sf::Texture* Mouse;

#pragma region Sound
	sf::SoundBuffer* gunShot;
	sf::SoundBuffer* klingSound;
#pragma endregion

	sf::Texture* enemy;
private:
	void cantLoad(LPCWSTR theerror);
};