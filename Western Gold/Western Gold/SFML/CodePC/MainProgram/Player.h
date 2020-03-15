#pragma once
#include "Entity.h"
#include "tile.h"

class Player : public Entity{
private:
	void move(DeltaTime time);
	int nrOfShoots;
	bool shooting;
	bool tossing;

	//Ray** rayTile;
	//int nrOfTiles;
	Ray** enemyRays;
	Ray** goldRays;
	int nrOfGold;
	int nrOfEnemies;
	void rotation();
	float speed;
	sf::RenderWindow* window;
public:
	void setEnemyRays(int nrOfEnemies);
	bool shoot();
	bool tossBullet();
	void gotBullet();
	int nrOfShotsLeft()const;
	//Ray *getTileRay(int nr);
	Ray* getEnemyRay(int nr);
	Ray* getGoldRay(int nr);
	Player(sf::Texture* tex, ResourceManager* rm, int nrOfEnemies, int nrOfGold);
	virtual~Player();
	void update(DeltaTime time);
	//debug
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};