#pragma once
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
class GameState
{
public:
	GameState(ResourceManager* rm);
	virtual ~GameState();
	virtual GameState* handleEvent(const sf::Event& event) = 0;
	virtual GameState* update(DeltaTime time) = 0;
	virtual void render(sf::RenderWindow& window) const = 0;

protected:
	void setGameState(GameState* state);
	GameState* getGameState() const;
	ResourceManager* getRm() const;
private:
	GameState* state;
	ResourceManager* rm;
};

