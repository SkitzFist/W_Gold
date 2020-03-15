#include "MenuState.h"
#include "PlayState.h"

MenuState::MenuState(ResourceManager* rm):
	GameState(rm)
{
	//config
	float titlePosOffset = 150.f;
	sf::Vector2f titlePos = {
		static_cast<float>(rm->getWindowWidth()) / 2.f,
		static_cast<float>((rm->getWindowHeight()) / 2.f) - titlePosOffset
	};
	float buttonOffset = 25.f;
	sf::Vector2f playButtonPos = {
		static_cast<float>(rm->getWindowWidth()) / 2.f,
		static_cast<float>((rm->getWindowHeight()) / 2.f) + buttonOffset
	};	
	sf::Vector2f exitButtonPos = {
		static_cast<float>(rm->getWindowWidth()) / 2.f,
		static_cast<float>((rm->getWindowHeight()) / 2.f) + (3*buttonOffset)
	};
	//setup
	playButton = new Button(rm->getWesternFont(), "Play", playButtonPos);
	exitButton = new Button(rm->getWesternFont(), "Exit", exitButtonPos);
	title = new Text(rm->getWesternFont(), "Western Gold", titlePos);

	playButton->markBox();
	currentButton = CurrentButton::play;
	//debug

}

MenuState::~MenuState()
{
	delete playButton;
	delete exitButton;
	delete title;
}

GameState* MenuState::handleEvent(const sf::Event& event)
{
	GameState* state = this;

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Return) {
			switch (currentButton)
			{
			case CurrentButton::play:
				state = new PlayState(getRm());
				break;
			case CurrentButton::exit:
				state = nullptr;
				break;
			default:
				break;
			}
			delete this;
		}

		if (event.key.code == sf::Keyboard::Up
			|| event.key.code == sf::Keyboard::Down) {
			switchBox();
		}
	}

	return state;
}

GameState* MenuState::update(DeltaTime delta)
{
	GameState* state = this;



	return state;
}

void MenuState::render(sf::RenderWindow& window) const
{
	window.draw(*playButton);
	window.draw(*exitButton);
	window.draw(*title);
}

void MenuState::switchBox()
{
	switch (currentButton)
	{
	case CurrentButton::play:
		playButton->unmarkBox();
		exitButton->markBox();
		currentButton = CurrentButton::exit;
		break;
	case CurrentButton::exit:
		exitButton->unmarkBox();
		playButton->markBox();
		currentButton = CurrentButton::play;
		break;
	default:
		break;
	}
}
