#pragma once
#include "GameState.h"
#include "Enemy.h"
#include "Level.h"
#include "Pathfinding.h"
#include "Player.h"
#include "Bullet.h"
#include "Collision.h"

class JoelState : public GameState
{
public:
	JoelState(ResourceManager* rm);
	~JoelState();
	// Inherited via GameState
	virtual GameState* handleEvent(const sf::Event& event) override;
	virtual GameState* update(DeltaTime time) override;
	virtual void render(sf::RenderWindow& window) const override;

private:
	Enemy* enemy;
	Level* level;
	Player* player;
	Collision* col;
	Bullet* bullet;
	bool canStart;
};
