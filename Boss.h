#ifndef BOSS_H
#define BOSS_H

#include "Monster.h"

class Boss : public Monster {
    protected:
        int max_health; // represents the max health of a monster
        int current_health; // current health of a monster
        int level; // level of the monster

    public:
        Boss(); //default constructer
        Boss(int level); //constructer for health based on level

};

#endif