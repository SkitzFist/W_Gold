#pragma once
#include "GameState.h"
#include "Level.h"
#include "EnemyHandler.h"
#include "Player.h"

class PlayState :
	public GameState
{
public:
	PlayState(ResourceManager* rm);
	virtual ~PlayState();

	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime delta) override;
	virtual void render(sf::RenderWindow& window) const override;


private:
	Level* level;
	Player* player;
	EnemyHandler enemyHandler;
};