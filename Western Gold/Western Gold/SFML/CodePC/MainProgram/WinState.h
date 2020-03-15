#pragma once
#include "GameState.h"
#include "Text.h"
#include "ButtonStates.h"
#include "Button.h"

class WinState:
	public GameState
{
public:
	WinState(ResourceManager* rm, int collectedGold);
	~WinState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow& window) const override;

private:
	//upgrade
	sf::RectangleShape upgradeBox;
	Text* upgradeTitle;
	Text* upgradeText;
	void setUpUpgradeMenu();

	//family
	sf::RectangleShape familyBox;
	void setUpFamilyMenu();
	Text* familyTitle;
	Text* familyText;

	//Gold
	sf::RectangleShape goldBox;
	void setUpGold(int collectedGold);
	Text* goldText;

	//Buttons
	void setUpButtons();
	CurrentButton currentButton;
	Button* nextButton;
	Button* exitButton;
	void switchButton();
};