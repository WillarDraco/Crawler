#ifndef WYVERN_H
#define WYVERN_H

#include "Monster.h"
#include "Player.h"

class Wyvern : public Monster{
    protected:
        int mana;

    public:
        Wyvern(Player* player); //default constructor

        void magic_attack (Player* player); //attack
        

        //getters and setters
        int get_mana();
        void set_mana(int mana);
};

#endif