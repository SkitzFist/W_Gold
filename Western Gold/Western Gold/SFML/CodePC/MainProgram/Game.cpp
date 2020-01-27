#include "Game.h"
#include "PlayState.h"
#include <thread>
#include <chrono>

Game::Game():
	window(sf::VideoMode(WIDTH, HEIGHT), "Mall"),
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	//config


	//setup
	rm = new ResourceManager();
	rm->windowSetup(WIDTH, HEIGHT);

	currentState = new PlayState(rm);

	//debug
}


Game::~Game()
{
	delete currentState;
	delete rm;
}

void Game::handleEvent()
{
	sf::Event event;
	while (window.pollEvent(event)) {

		if (currentState != nullptr) {
			currentState->handleEvent(event);
		}	
		if (event.type == sf::Event::Closed ||
			event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
			window.close();
		}
	}
}

void Game::run()
{
	while (window.isOpen())
	{
		handleEvent();
		update();
		render();
	}
}

void Game::update()
{
	elapsedTimeSinceLastUpdate += clock.restart();
	while(elapsedTimeSinceLastUpdate >= timePerFrame) {
		sf::Time delta;
		float dt = std::fmin(elapsedTimeSinceLastUpdate.asSeconds(), timePerFrame.asSeconds());
		delta = sf::seconds(dt);

		if(currentState != nullptr) {
			currentState->update(delta);
		}

		elapsedTimeSinceLastUpdate -= delta;
	}
}


void Game::render()
{
	window.clear();
	if (currentState != nullptr) {
		currentState->render(window);
	}
	window.display();
}
