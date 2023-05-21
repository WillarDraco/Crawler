#ifndef UPGRADE_H
#define UPGRADE_H

#include "Player.h"

class Upgrade{
    protected:
    bool upgrade_strength;
    bool upgrade_agility;
    bool upgrade_mana;


    public:
    Upgrade(); //default constructer



    
    void choose_strength(); //sets upgrade strength to true
    void choose_agility(); //sets upgrade agility to true
    void choose_mana(); //sets upgrade agility to true

    


};
#endif
