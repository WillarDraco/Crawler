#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"
#include "Player.h"

class Goblin : public Monster{
    protected:
        int strength;

    public:
        Goblin(int level); //default constructor

        void punch(Player* player); // basic attack

        void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)
        

        //getters and setters
        int get_strength();
        void set_strength(int);
};

#endif