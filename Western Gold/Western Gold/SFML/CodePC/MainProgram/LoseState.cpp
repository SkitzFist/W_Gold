#include "LoseState.h"

LoseState::LoseState(ResourceManager* rm):
	GameState(rm)
{
	//config

	//setup
	setUpUpgradeMenu();

	//debug
}

LoseState::~LoseState()
{
	delete upgradeText;
	delete upgradeTitle;
}

GameState* LoseState::handleEvent(const sf::Event& event)
{
	GameState* state = this;

	return state;
}

GameState* LoseState::update(DeltaTime delta)
{
	GameState* state = this;

	return state;
}

void LoseState::render(sf::RenderWindow& window) const
{
	window.draw(upgradeBox);
}

void LoseState::setUpUpgradeMenu()
{
	//config
	sf::Vector2f upgradeBoxPos = {
		500.f,
		500.f
	};
	sf::Vector2f upgradeBoxSize = {
		400.f,
		900.f
	};
	sf::Vector2f upgradeTitlePos = {
		0.f,
		0.f
	};
	//setup
	upgradeTitle = new Text(getRm()->getBasicFont(), "Upgrades", upgradeTitlePos);

	upgradeBox.setSize(upgradeBoxSize);
	upgradeBox.setFillColor(sf::Color::Black);
	upgradeBox.setPosition(upgradeBoxPos);
	//debug
}

void LoseState::setUpFamilyMenu()
{
}

void LoseState::setUpButtons()
{
}
