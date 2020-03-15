#pragma once
#include "GameState.h"
#include "Button.h"
#include "Text.h"
#include "ButtonStates.h"

class MenuState :
	public GameState
{
public:
	MenuState(ResourceManager* rm);
	~MenuState();
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow& window) const override;

private:

	CurrentButton currentButton;
	Button* playButton;
	Button* exitButton;
	Text* title;
	void switchBox();
};