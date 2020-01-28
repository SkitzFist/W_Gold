#include "SimonState.h"

SimonState::SimonState(ResourceManager* rm):
	GameState(rm)
{
	setupText();
	setGameState(this);
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

	//std::cout << time.dt() << std::endl;
	text.setString(std::to_string(time.dt()));

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
