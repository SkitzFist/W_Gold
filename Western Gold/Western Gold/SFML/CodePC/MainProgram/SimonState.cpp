#include "SimonState.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm)
{
	setupText();
	setGameState(this);
	test.LoadSound("../../Bin/Sound/test.wav", 5);
}

SimonState::~SimonState()
{
}

GameState* SimonState::handleEvent(const sf::Event& event)
{
	setGameState(this);


	return getGameState();
}

GameState* SimonState::update(DeltaTime time)
{
	setGameState(this);

	text.setString(std::to_string(time.dt()));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&test.IfSoundStopped()) {
		test.PlayLoadSound();
	}

	return getGameState();
}

void SimonState::render(sf::RenderWindow& window) const
{

	window.draw(this->text);

}

void SimonState::setupText()
{
	text.setFont(*getRm()->getBasicFont());
	sf::Vector2f pos{
		getRm()->getWindowWidth() / 2.f,
		getRm()->getWindowHeight() / 2.f
	};
	text.setPosition(pos);
}
