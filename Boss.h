#ifndef BOSS_H
#define BOSS_H

#include "Monster.h"

class Boss : public Monster {
    protected:
    
    public:
        Boss(); //default constructer
        Boss(int level); //constructer for health based on level

};

#endif