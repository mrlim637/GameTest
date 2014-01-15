#ifndef COLLISION_H
#define COLLISION_H

#include "GenericObj.h"

class Collision
{
    public:
        Collision();
        ~Collision();

        bool isCollided(GenericObj player, vector<GenericObj> objList);
    protected:
    private:
};

#endif // COLLISION_H
