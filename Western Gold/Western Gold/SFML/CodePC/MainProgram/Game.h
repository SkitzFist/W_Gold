#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "GameState.h"

class Game
{
public:
	static const int WIDTH = 1000;
	static const int HEIGHT = 700;
public:
	Game();
	~Game();
	void run();

private:
	sf::Clock clock;
	sf::Time elapsedTimeSinceLastUpdate;
	sf::Time timePerFrame;
	sf::RenderWindow* window;
	ResourceManager* rm;
	GameState* currentState;
	DeltaTime time;

	sf::Sprite mouse;
	//debug

private:
	void update();
	void handleEvent();
	void render();

};