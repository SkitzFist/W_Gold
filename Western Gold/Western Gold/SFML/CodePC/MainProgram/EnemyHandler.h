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
private:
	Enemy** enemies;
	int nrOf;
	int cap;

	void expandArr();
	void removeAt(int i);
	void add(Enemy* enemy);
};

