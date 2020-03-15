#pragma once
#include "GameState.h"
#include "Button.h"
#include "Text.h"
#include "ButtonStates.h"

class LoseState :
	public GameState
	{
	public:
		LoseState(ResourceManager * rm, GameState* loseState);
		~LoseState();
		// Inherited via GameState
		virtual GameState* handleEvent(const sf::Event& event) override;
		virtual GameState* update(DeltaTime delta) override;
		virtual void render(sf::RenderWindow& window) const override;
	private:
		GameState* loseState;
		Text GameOver;
		Button* restart;
		Button* menu;
		sf::RectangleShape backGrey;
		CurrentButton currentButton;

		void switchButton();
		
};