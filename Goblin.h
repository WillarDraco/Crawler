#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"
#include "Player.h"

class Goblin : public Monster{
    protected:
        int strength;
        Weapon** goblin_weapon;
    
    public:
        Goblin(Player* player); //constructor

        void attack(Player* player); // basic attack

        void equipWeapon(Weapon* goblin_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* goblin_weapon); // sets current weapon to  “” (removes weapon bonuses)
        

        //getters and setters
        int get_strength();
        void set_strength(int);
};

#endif