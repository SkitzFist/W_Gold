#pragma once
#include "GameState.h"
#include "Button.h"
#include "Text.h"
#include "ButtonStates.h"

class PauseState:
	public GameState
{
public:
	PauseState(ResourceManager* rm, GameState* pausedState);
	~PauseState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow& window) const override;

private:
	GameState* pausedState;
	sf::RectangleShape box;
	Button* resumeButton;
	Button* exitButton;
	Text* pauseText;
	CurrentButton currentButton;

	bool willExit;

	void switchButton();
};

