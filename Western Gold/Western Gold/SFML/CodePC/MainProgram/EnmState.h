#pragma once
#include "DeltaTime.h"
#include "tile.h"
class Enemy;

class EnmState
{
public:
    EnmState(Enemy* enm);
    virtual ~EnmState();
    virtual EnmState* update(DeltaTime time) = 0;

protected:
    Enemy* getEnm() const;
    tile* getTargetTile() const;
    void setTargetTile(tile* tile);
    tile* getCurrentTile() const;
    void setCurrentTile(tile* tile);
    tile* getNextTile()const;
    void setNextTile(tile* tile);

    void setDirTowardsNextTile();
    bool hasReachedTile(tile* t) const;
    void calculatePath();
    void rotate();

private:
    tile* targetTile;
    tile* currentTile;
    tile* nextTile;
 
    Enemy* enm;
};

