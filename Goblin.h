#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"
#include "Player.h"

class Goblin : public Monster{
    protected:
        int strength;
        bool has_weapon;
    
    public:
        Goblin(int level, Player* player); //constructor

        void attack(Player* player); // basic attack

        void equipWeapon(); // sets current weapon (weapon bonuses)
        void unequipWeapon(); // sets current weapon to  “” (removes weapon bonuses)
        

        //getters and setters
        int get_strength();
        void set_strength(int);
};

#endif