#include "PauseState.h"

PauseState::PauseState(ResourceManager* rm, GameState* otherState):
	GameState(rm)
{
	//config

	//setup
	willExit = false;
	//debug
}

PauseState::~PauseState()
{
	delete resumeButton;
	delete exitButton;
	delete pauseText;
}

GameState* PauseState::handleEvent(const sf::Event& event)
{
	GameState* state = this;


	return state;
}

GameState* PauseState::update(DeltaTime delta)
{
	GameState* state = this;


	return state;
}

void PauseState::render(sf::RenderWindow& window) const
{
	if (!willExit) {
		otherState->render(window);
	}

	window.draw(box);
	window.draw(*resumeButton);
	window.draw(*exitButton);
}

void PauseState::switchButton()
{
	
}
