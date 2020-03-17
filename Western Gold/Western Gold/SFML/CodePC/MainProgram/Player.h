#pragma once
#include "Entity.h"
#include "tile.h"

class Player : public Entity{
private:
	void move(DeltaTime time);
	int nrOfShoots;
	bool shooting;
	bool tossing;

	Ray** enemyRays;
	Ray** goldRays;
	int nrOfGold;
	int nrOfEnemies;
	void rotation();
	float speed;
	sf::RenderWindow* window;
	int nrOfGoldTaken;
public:
	void setEnemyRays(int nrOfEnemies);
	void setGoldRays(int nrOfGold);
	bool shoot();
	bool tossBullet();
	void gotBullet();
	int nrOfShotsLeft()const;
	void addNrOfGoldTaken();
	int getNrOfGold()const;

	Ray* getEnemyRay(int nr);
	Ray* getGoldRay(int nr);
	Player(sf::Texture* tex, ResourceManager* rm, int nrOfEnemies);
	virtual~Player();
	void update(DeltaTime time);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};