#include "LoseState.h"
#include "MenuState.h"
#include "PlayState.h"

LoseState::LoseState(ResourceManager* rm, GameState* loseState):
GameState(rm),
GameOver(rm->getWesternFont(),"GAME OVER", sf::Vector2f(rm->getView()->getCenter().x, rm->getView()->getCenter().y - 100), 70U)
{
	this->loseState = loseState;
	sf::Vector2f boxPos = {
		rm->getView()->getCenter().x,
		rm->getView()->getCenter().y
	};
	currentButton = CurrentButton::restart;
	menu = new Button(rm->getWesternFont(), "Menu", sf::Vector2f(boxPos.x - 100, boxPos.y));
	restart = new Button(rm->getWesternFont(), "Restart", sf::Vector2f(boxPos.x + 100, boxPos.y));
	sf::Color color;
	color.r = 128;
	color.g = 128;
	color.b = 128;
	color.a = 100;
	backGrey.setFillColor(color);
	backGrey.setPosition(boxPos.x - (rm->getWindowWidth() / 2), boxPos.y- (rm->getWindowHeight() / 2));
	backGrey.setSize(sf::Vector2f(rm->getWindowWidth(), rm->getWindowHeight()));
}



LoseState::~LoseState()
{
	delete menu;
	delete restart;
	if (loseState != nullptr) {
		delete loseState;
	}
}

GameState* LoseState::handleEvent(const sf::Event& event)
{
	GameState* state = this;
	if (event.type == sf::Event::KeyReleased) {
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
			case CurrentButton::restart:
				state = new PlayState(getRm());
				delete this;
				break;
			case CurrentButton::exit:
				state = new MenuState(getRm());
				delete loseState;
				delete this;
				break;
			default:
				break;
			}
		}
	}

	return state;
}

GameState* LoseState::update(DeltaTime delta)
{
	GameState* state = this;


	return state;
}

void LoseState::render(sf::RenderWindow& window) const
{
	loseState->render(window);
	window.draw(backGrey);
	window.draw(GameOver);
	window.draw(*this->menu);
	window.draw(*this->restart);
}

void LoseState::switchButton()
{
	switch (currentButton)
	{
	case CurrentButton::restart:
		restart->unmarkBox();
		menu->markBox();
		currentButton = CurrentButton::exit;
		break;
	case CurrentButton::exit:
		menu->unmarkBox();
		restart->markBox();
		currentButton = CurrentButton::restart;
		break;
	default:
		break;
	}
}
