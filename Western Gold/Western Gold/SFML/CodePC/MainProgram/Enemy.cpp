#include "Enemy.h"
#include "PatrollState.h"
#include "SeachState.h"
#include "Collision.h"

Enemy::Enemy(ResourceManager* rm, int nrOfRays, Grid* grid, Player* player):
Entity(rm->getEnemy(), rm, nrOfRays)
{
	//config
	seeDistance = 400;
	//setup
	patroll = nullptr;
	this->player = player;
	pathfinding = new Pathfinding(grid);
	currentState = nullptr;
	this->grid = grid;
	dir = { 0.f, 0.f };
	isPlayerInSight = false;
	shootingSound = new Sound();
	collision = nullptr;
	//debug

}

Enemy::~Enemy()
{
	delete patroll;
	delete pathfinding;
	delete currentState;
	delete shootingSound;
}

void Enemy::update(DeltaTime delta)
{
	float speed = 150.f * static_cast<float>(delta.dt());
	if (currentState != nullptr) {
		currentState = currentState->update(delta);
		moveSprite(dir, speed);
	}
	Entity::update(delta);
}

bool Enemy::shoot()
{
	return false;
}

void Enemy::engageSearch(sf::Vector2f pos)
{
	currentState = new SeachState(this, pos);
}

Pathfinding* Enemy::getPathfinding() const
{
	return pathfinding;
}

void Enemy::setPatrollPoints(PatrollPoints* patroll)
{
	this->patroll = patroll;
	currentState = new PatrollState(this);
}

Grid* Enemy::getGrid() const
{
	return grid;
}

void Enemy::setDir(sf::Vector2f dir)
{
	this->dir = dir;
}

sf::Vector2f Enemy::getDir() const
{
	return dir;
}

bool Enemy::isShooting()
{
	return false;
}

int Enemy::getSeeDistance() const
{
	return this->seeDistance;
}

void Enemy::changePlayerInSight(bool Sight)
{
	this->isPlayerInSight = Sight;
}

void Enemy::setCollision(Collision& collision)
{
	this->collision = &collision;
}

Collision* Enemy::getCollision()
{
	return collision;
}

Sound* Enemy::getSound() const
{
	return shootingSound;
}

bool Enemy::getIsPlayerInSight()
{
	return isPlayerInSight;
}

PatrollPoints* Enemy::getPatroll()
{
	return patroll;
}


Player* Enemy::getPlayer() const
{
	return player;
}