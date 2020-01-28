#include "Game.h"
#include "PlayState.h"
#include <thread>
#include <chrono>
#include "SimonState.h"

Game::Game():
	window(sf::VideoMode(WIDTH, HEIGHT), "Mall"),
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	//config


	//setup
	rm = new ResourceManager();
	rm->windowSetup(WIDTH, HEIGHT);

	currentState = new SimonState(rm);

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
		if (event.type == sf::Event::Closed) {
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

		time.restartClock();
		if(currentState != nullptr) {
			currentState->update(time);
		}
		elapsedTimeSinceLastUpdate -= timePerFrame;
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
