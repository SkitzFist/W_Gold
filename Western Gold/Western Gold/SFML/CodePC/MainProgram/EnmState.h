#pragma once
#include "DeltaTime.h"
#include "tile.h"
#include <SFML/Graphics.hpp>
class Enemy;

class EnmState
{
public:
    EnmState(Enemy* enm);
    virtual ~EnmState();
    virtual EnmState* update(DeltaTime time) = 0;

protected:
    Enemy* getEnm() const;

private:
    Enemy* enm;
};

