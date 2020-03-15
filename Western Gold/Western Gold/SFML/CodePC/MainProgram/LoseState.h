#pragma once
#include "GameState.h"
#include "Text.h"
class LoseState:
	public GameState
{
public:
	LoseState(ResourceManager* rm);
	~LoseState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow& window) const override;

private:
	
	sf::RectangleShape upgradeBox;
	Text* upgradeTitle;
	Text* upgradeText;

	void setUpUpgradeMenu();
	void setUpFamilyMenu();
	void setUpButtons();
};

