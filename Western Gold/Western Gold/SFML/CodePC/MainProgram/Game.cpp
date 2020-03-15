#include "Game.h"
#include "PlayState.h"
#include <thread>
#include "SimonState.h"
#include "JoelState.h"
#include "MenuState.h"
#include "LoadState.h"

Game::Game() :
	timePerFrame(sf::seconds(1.0f / 60.0f)),
	elapsedTimeSinceLastUpdate(sf::Time::Zero)
{
	//config
	sf::ContextSettings settings(0U, 0U, 16U);
	auto vMode = sf::VideoMode::getDesktopMode();
	window = new sf::RenderWindow();
	window->create(vMode, "Western Gold", 7U, settings);
	window->setMouseCursorVisible(false);
	//setup
	rm = new ResourceManager();
	rm->windowSetup(window);
	currentState = new LoadState(rm);
	rm->loadMouse();
	mouse.setTexture(*rm->getMouse());
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
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mPos = window->mapPixelToCoords(pixelPos);
	mouse.setPosition(mPos);
	this->time.restartClock();
	if (currentState != nullptr) {
		currentState = currentState->update(time);
	}

}


void Game::render()
{
	window->clear(sf::Color::Magenta);
	if (currentState != nullptr) {
		currentState->render(*window);
	}
	window->draw(mouse);
	window->display();
}