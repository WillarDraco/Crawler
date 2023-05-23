#ifndef SLIME_H
#define SLIME_H

#include "Monster.h"
#include "Player.h"

class Slime : public Monster{
    protected:

    public:
        Slime(Player* player); //default constructor

        void attack(Player* player); //attack
        

        //getters and setters
        int get_strength();
        int get_mana();

        void set_strength(int strength);
        void set_mana(int mana);
};

#endif