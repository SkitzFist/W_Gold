#pragma once
#include "DeltaTime.h"
#include "Enemy.h"
class EnemyHandler
{
public:
	EnemyHandler();
	~EnemyHandler();
	void update(DeltaTime time);
	int getNrOf() const;
	Enemy** getEnemies()const;
	void add(Enemy* enemy);
private:
	Enemy** enemies;
	int nrOf;
	int cap;

	void expandArr();
	void removeAt(int i);
};

