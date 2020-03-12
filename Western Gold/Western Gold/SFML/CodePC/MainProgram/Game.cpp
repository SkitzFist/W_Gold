#include "Game.h"
#include "PlayState.h"
#include <thread>
#include <chrono>
#include "SimonState.h"
#include "JoelState.h"
#include "MenuState.h"

Game::Game() :
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	//config
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Western Gold");

	//setup
	rm = new ResourceManager();
	rm->windowSetup(window);
	rm->loadTilesAndLevels();

	currentState = new MenuState(rm);

	//debug
}


Game::~Game()
{
	delete currentState;
	delete rm;
	delete window;
}

void Game::handleEvent()
{
	sf::Event event;
	while (window->pollEvent(event)) {

		if (currentState != nullptr) {
			currentState = currentState->handleEvent(event);
		}
		if (event.type == sf::Event::Closed 
			|| currentState == nullptr) {
			window->close();
		}
	}
}

void Game::run()
{
	while (window->isOpen())
	{
		handleEvent();
		update();
		render();
	}
}

void Game::update()
{
	elapsedTimeSinceLastUpdate += clock.restart();
	if (elapsedTimeSinceLastUpdate >= timePerFrame) {

		this->time.restartClock();
		if (currentState != nullptr) {
			currentState = currentState->update(time);
		}
		elapsedTimeSinceLastUpdate -= timePerFrame;
	}
}


void Game::render()
{
	window->clear(sf::Color::Magenta);
	if (currentState != nullptr) {
		currentState->render(*window);
	}
	window->display();
}