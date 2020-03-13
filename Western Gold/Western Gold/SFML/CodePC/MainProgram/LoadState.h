#pragma once
#include <thread>
#include "GameState.h"
#include "Text.h"

class LoadState:
	public GameState
{
public:
	LoadState(ResourceManager* rm);
	~LoadState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow& window) const override;

private:
	sf::Text loadText;
	int loadStatus;
	
	std::thread tileThread;
	std::thread spriteThread;
	std::thread soundThread;
	
	void loadTilesAndLevel();
	void loadSprites();
	void loadSound();
};

