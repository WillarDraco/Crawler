#ifndef BOSS_H
#define BOSS_H

#include "Monster.h"
#include "Player.h"

class Boss : public Monster {
    protected:
    
    public:
        Boss(); //default constructer
        Boss(Player* player); //constructer

};

#endif