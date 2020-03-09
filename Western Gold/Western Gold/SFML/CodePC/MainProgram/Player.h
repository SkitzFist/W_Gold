#pragma once
#include "Entity.h"
#include "tile.h"

class Player : public Entity{
private:
	void move(DeltaTime time);
	int nrOfShoots;
	bool shooting;
	bool tossing;

	Ray** rayTile;
	int nrOfTiles;
	Ray** enemyRays;
	int nrOfEnemies;

	void rotation();
	float speed;
	sf::RenderWindow* window;
public:
	bool shoot();
	bool tossBullet();
	Ray *getTileRay(int nr);
	Ray* getEnemyRay(int nr);
	Player(sf::Texture* tex, ResourceManager* rm, int nrOfTiles, int nrOfEnemies);
	virtual~Player();
	void update(DeltaTime time);
	//debug
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};