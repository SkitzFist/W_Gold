#pragma once
#include "Gold.h"
class GoldHandler
{
public:
	GoldHandler();
	~GoldHandler();
	Gold** getGold() const;
	void add(Gold* gold);
	void update(DeltaTime time);
	int getNrOf() const;

private:
	Gold** gold;
	int nrOf;
	int cap;

	void expandArr();
	void removeAt(int i);
};

