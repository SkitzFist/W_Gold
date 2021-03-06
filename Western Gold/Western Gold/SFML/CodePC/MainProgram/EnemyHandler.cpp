#include "EnemyHandler.h"
#include "GetDistance.h"

EnemyHandler::EnemyHandler()
{
	//setup
	nrOf = 0;
	cap = 20;
	enemies = new Enemy * [cap] {nullptr};
}

EnemyHandler::~EnemyHandler()
{
	for (int i = 0; i < nrOf; ++i) {
		delete enemies[i];
	}
	delete[] enemies;
}

void EnemyHandler::update(DeltaTime time)
{
	for (int i = 0; i < nrOf; ++i) {		
		if (enemies[i]->isDead()) {
			removeAt(i);
		}
		else {
			enemies[i]->update(time);
		}
	}
}

int EnemyHandler::getNrOf() const
{
	return nrOf;
}

Enemy** EnemyHandler::getEnemies() const
{
	return enemies;
}

void EnemyHandler::expandArr()
{
	cap += 20;
	Enemy** tmp = new Enemy * [cap] {nullptr};
	for (int i = 0; i < nrOf; ++i) {
		tmp[i] = enemies[i];
	}
	delete[] enemies;
	enemies = tmp;
	tmp = nullptr;
}

void EnemyHandler::removeAt(int i)
{
	delete enemies[i];
	enemies[i] = enemies[--nrOf];
	enemies[nrOf] = nullptr;
}

void EnemyHandler::add(Enemy* enemy)
{
	if (nrOf == cap) {
		expandArr();
	}
	enemies[nrOf++] = enemy;
}

void EnemyHandler::setCollision(Collision& col)
{
	for (int i = 0; i < nrOf; ++i) {
		enemies[i]->setCollision(col);
	}
}

void EnemyHandler::activateSearchState(sf::Vector2f pos)
{
	float maxDistance = 600.f;

	for (int i = 0; i < nrOf; ++i) {
		float distance = getDistance(pos.x, pos.y, enemies[i]->getPosition().x, enemies[i]->getPosition().y);
		if (distance < maxDistance) {
			enemies[i]->engageSearch(pos);
		}
	}
}
