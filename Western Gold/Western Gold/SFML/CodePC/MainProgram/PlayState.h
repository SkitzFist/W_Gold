#pragma once
#include "GameState.h"
#include "Level.h"
#include "EnemyHandler.h"
#include "Player.h"
#include "Text.h"
#include "Collision.h"
#include "UI.h"
#include "Bullet.h"
#include "GoldHandler.h"

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
	//objects
	Level* level;
	Player* player;
	Bullet** bullets;

	//nrOf
	int nrOfBullets;
	const int NR_OF_GOLD_TO_WIN = 6;
	
	bool canStart;

	//other
	Collision collision;
	EnemyHandler enemyHandler;
	GoldHandler goldHandler;
	UI ui;

	sf::View camera;
};