#include "PauseState.h"

PauseState::PauseState(ResourceManager* rm, GameState* pausedState):
	GameState(rm)
{
	//config
	sf::Color boxColor = { 0, 0, 0, 50 };
	float buttonOffset = 25.f;

	sf::Vector2f resumeButtonPos = {
		rm->getView()->getCenter().x,
		rm->getView()->getCenter().y + buttonOffset
	};
	sf::Vector2f exitButtonPos = {
		rm->getView()->getCenter().x,
		rm->getView()->getCenter().y + buttonOffset + (3 * buttonOffset)
	};

	sf::Vector2f boxPos = {
		rm->getView()->getCenter().x,
		rm->getView()->getCenter().y
	};

	//setup
	this->pausedState = pausedState;
	willExit = false;
	sf::Vector2f boxSize = { 
		static_cast<float>(rm->getWindowWidth()), 
		static_cast<float>(rm->getWindowWidth()) 
	};
	box.setSize(boxSize);
	box.setOrigin(boxSize.x / 2.f, boxSize.y / 2.f);
	box.setFillColor(boxColor);
	box.setPosition(boxPos);

	resumeButton = new Button(rm->getBasicFont(), "Resume", resumeButtonPos);
	exitButton = new Button(rm->getBasicFont(), "Exit", exitButtonPos);

	resumeButton->markBox();
	currentButton = CurrentButton::resume;
	sf::Vector2f textPos = {
		resumeButtonPos.x,
		resumeButtonPos.y - (4.f * buttonOffset)
	};
	pauseText = new Text(rm->getBasicFont(), "Paused", textPos);

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
	if (event.type == sf::Event::KeyPressed) {
		if (
		      event.key.code == sf::Keyboard::W
			|| event.key.code == sf::Keyboard::S
			|| event.key.code == sf::Keyboard::Up
			|| event.key.code == sf::Keyboard::Down) {
			switchButton();
		}
		else if (event.key.code == sf::Keyboard::Enter) {
			switch (currentButton)
			{
			case CurrentButton::resume:
				state = pausedState;
				delete this;
				break;
			case CurrentButton::exit:
				state = nullptr;
				delete pausedState;
				delete this;
				break;
			default:
				break;
			}
		}
	}

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
		pausedState->render(window);
	}

	window.draw(box);
	window.draw(*resumeButton);
	window.draw(*exitButton);
	window.draw(*pauseText);
}

void PauseState::switchButton()
{
	switch (currentButton)
	{
	case CurrentButton::resume:
		resumeButton->unmarkBox();
		exitButton->markBox();
		currentButton = CurrentButton::exit;
		break;
	case CurrentButton::exit:
		exitButton->unmarkBox();
		resumeButton->markBox();
		currentButton = CurrentButton::resume;
		break;
	default:
		break;
	}
}