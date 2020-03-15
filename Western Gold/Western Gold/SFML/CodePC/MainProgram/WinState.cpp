#include "WinState.h"

#include <iostream>
WinState::WinState(ResourceManager* rm):
	GameState(rm)
{
	//config

	//setup
	setUpUpgradeMenu();
	setUpButtons();
	setUpFamilyMenu();
	setUpGold();
	//debug
}

WinState::~WinState()
{
	delete upgradeText;
	delete upgradeTitle;
	delete familyTitle;
	delete familyText;
}

GameState* WinState::handleEvent(const sf::Event& event)
{
	GameState* state = this;
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Button::Right) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(*getRm()->getWindow());
			std::cout << mousePos.x << "." << mousePos.y << std::endl;
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
	window.draw(upgradeBox);
	window.draw(goldBox);
	window.draw(familyBox);
	window.draw(*upgradeTitle);
	window.draw(*upgradeText);
	window.draw(*familyTitle);
	window.draw(*familyText);
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
		upgradeBoxPos.y - 100.f
	};

	sf::Vector2f upgradeTextPos = {
		(upgradeBoxPos.x + upgradeBoxSize.x) / 2.f,
		(upgradeBoxPos.y + upgradeBoxPos.y) / 2.f
	};
	//setup
	upgradeTitle = new Text(getRm()->getBasicFont(), "Upgrades", upgradeTitlePos);

	upgradeBox.setSize(upgradeBoxSize);
	upgradeBox.setFillColor(sf::Color::Black);
	upgradeBox.setPosition(upgradeBoxPos);

	upgradeText = new Text(getRm()->getBasicFont(), "Not available in Alpha", upgradeTextPos);

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
		(familyBoxPos.x + familyBoxSize.x) / 2.f,
		familyBoxPos.y - 100.f
	};
	sf::Vector2f familyTextPos = {
		(familyBoxPos.x + familyBoxSize.x) / 2.f,
		familyBoxPos.y + (familyBoxSize.y / 2.f)
	};

	//setup
	familyBox.setSize(familyBoxSize);
	familyBox.setFillColor(sf::Color::Black);
	familyBox.setPosition(familyBoxPos);
	familyTitle = new Text(getRm()->getBasicFont, "Family", familyTitlePos);
	familyText = new Text(getRm()->getBasicFont(), "Not available in Alpha", familyTextPos);
}

void WinState::setUpGold()
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
	//setup
	goldBox.setSize(goldBoxSize);
	goldBox.setFillColor(sf::Color::Green);
	goldBox.setPosition(goldBoxPos);
	//debug
}

void WinState::setUpButtons()
{
}
