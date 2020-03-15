#include "GoldHandler.h"

GoldHandler::GoldHandler()
{
	//config

	//setup
	nrOf = 0;
	cap = 12;
	gold = new Gold * [cap] {nullptr};
	//debug
}

GoldHandler::~GoldHandler()
{
	for (int i = 0; i < nrOf; ++i) {
		delete gold[i];
	}
	delete[] gold;
}

Gold** GoldHandler::getGold() const
{
	return gold;
}

void GoldHandler::add(Gold* gold)
{
	if (nrOf == cap) {
		expandArr();
	}
	this->gold[nrOf++] = gold;
}

void GoldHandler::update(DeltaTime time)
{
	for (int i = 0; i < nrOf; ++i) {
		gold[i]->update(time);
	}
}

int GoldHandler::getNrOf() const
{
	return nrOf;
}

void GoldHandler::expandArr()
{
	cap += 12;
	Gold** tmp = new Gold*[cap];

	for (int i = 0; i < nrOf; ++i) {
		tmp[i] = gold[i];
	}
	delete[] gold;
	gold = tmp;
	tmp = nullptr;
}

void GoldHandler::removeAt(int i)
{
	delete gold[i];
	gold[i] = gold[--nrOf];
	gold[nrOf] = nullptr;
}
