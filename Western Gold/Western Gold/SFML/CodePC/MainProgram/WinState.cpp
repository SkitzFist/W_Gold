#include "WinState.h"
#include "MenuState.h"
#include "PlayState.h"

WinState::WinState(ResourceManager* rm, int collectedGold):
	GameState(rm)
{
	//config

	//setup
	setUpUpgradeMenu();
	setUpFamilyMenu();
	setUpGold(collectedGold);
	setUpButtons();
	//debug
	currentButton = CurrentButton::next;
	nextButton->markBox();
}

WinState::~WinState()
{
	delete upgradeText;
	delete upgradeTitle;
	delete familyTitle;
	delete familyText;
	delete goldText;
	delete nextButton;
	delete exitButton;
}

GameState* WinState::handleEvent(const sf::Event& event)
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
		else if (event.key.code == sf::Keyboard::Enter
			|| event.key.code == sf::Keyboard::Space) {
			switch (currentButton)
			{
			case CurrentButton::exit:
				state = new MenuState(getRm());
				delete this;
				break;
			case CurrentButton::next:
				state = new PlayState(getRm());
				delete this;
				break;
			default:
				break;
			}
		}
	}
	return state;
}

GameState* WinState::update(DeltaTime delta)
{
	GameState* state = this;

	return state;
}

void WinState::render(sf::RenderWindow& window) const
{
	window.setView(window.getDefaultView());
	window.draw(upgradeBox);
	window.draw(goldBox);
	window.draw(familyBox);
	window.draw(*upgradeTitle);
	window.draw(*upgradeText);
	window.draw(*familyTitle);
	window.draw(*familyText);
	window.draw(*goldText);
	window.draw(*nextButton);
	window.draw(*exitButton);
}

void WinState::setUpUpgradeMenu()
{
	//config
	sf::Vector2f upgradeBoxPos = {
		80.f,
		147.f
	};
	sf::Vector2f upgradeBoxSize = {
		1000.f,
		800.f
	};
	sf::Vector2f upgradeTitlePos = {
		(upgradeBoxPos.x + upgradeBoxSize.x) / 2.f,
		upgradeBoxPos.y - 26.f
	};

	sf::Vector2f upgradeTextPos = {
		(upgradeBoxPos.x + upgradeBoxSize.x) / 2.f,
		(upgradeBoxPos.y + upgradeBoxSize.y) / 2.f
	};
	//setup
	upgradeTitle = new Text(getRm()->getWesternFont(), "Upgrades", upgradeTitlePos);

	upgradeBox.setSize(upgradeBoxSize);
	upgradeBox.setFillColor(sf::Color::Black);
	upgradeBox.setPosition(upgradeBoxPos);

	upgradeText = new Text(getRm()->getWesternFont(), "Not available in Alpha", upgradeTextPos);

	//debug
}

void WinState::setUpFamilyMenu()
{
	//config
	sf::Vector2f familyBoxPos = {
		1200.f,
		147.f
	};
	sf::Vector2f familyBoxSize = {
		500.f,
		200.f
	};
	sf::Vector2f familyTitlePos = {
		familyBoxPos.x + (familyBoxSize.x / 2.f),
		familyBoxPos.y - 26.f
	};
	sf::Vector2f familyTextPos = {
		familyBoxPos.x + (familyBoxSize.x / 2.f),
		familyBoxPos.y + (familyBoxSize.y / 2.f)
	};

	//setup
	familyBox.setSize(familyBoxSize);
	familyBox.setFillColor(sf::Color::Black);
	familyBox.setPosition(familyBoxPos);
	familyTitle = new Text(getRm()->getWesternFont(), "Family", familyTitlePos);
	familyText = new Text(getRm()->getWesternFont(), "Not available in Alpha", familyTextPos);
}

void WinState::setUpGold(int collectedGold)
{
	//config
	sf::Vector2f goldBoxPos = {
		1200.f,
		400.f
	};
	sf::Vector2f goldBoxSize = {
		500.f,
		100.f
	};
	sf::Vector2f goldtextPos = {
		goldBoxPos.x + (goldBoxSize.x /2.f),
		goldBoxPos.y + (goldBoxSize.y / 2.f)
	};
	//setup
	goldBox.setSize(goldBoxSize);
	goldBox.setFillColor(sf::Color::Black);
	goldBox.setPosition(goldBoxPos);

	std::string goldString = "Gold : " + std::to_string(collectedGold) + "/ 12";
	goldText = new Text(getRm()->getWesternFont(), goldString, goldtextPos);
	//debug
}

void WinState::setUpButtons()
{
	//config
	sf::Vector2f nextButtonPos = {
		goldBox.getPosition().x + (goldBox.getSize().x / 2.f),
		goldBox.getPosition().y + 400.f
	};
	sf::Vector2f exitButtonPos = {
		nextButtonPos.x,
		nextButtonPos.y + 60.f
	};
	//setup
	goldBox.getPosition().x;
	nextButton = new Button(getRm()->getWesternFont(), "Next", nextButtonPos, 55);
	exitButton = new Button(getRm()->getWesternFont(), "Exit", exitButtonPos, 55);
}

void WinState::switchButton()
{
	switch (currentButton)
	{
	case CurrentButton::exit:
		exitButton->unmarkBox();
		nextButton->markBox();
		currentButton = CurrentButton::next;
		break;
	case CurrentButton::next:
		nextButton->unmarkBox();
		exitButton->markBox();
		currentButton = CurrentButton::exit;
		break;
	default:
		break;
	}
}