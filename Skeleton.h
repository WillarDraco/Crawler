#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"
#include "Player.h"

class Skeleton : public Monster{
    protected:
        int agility;
        bool has_weapon;

    public:
        Skeleton(int level); //default constructor

        void attack(Player* player); //attack


        void equipWeapon(); // sets current weapon (weapon bonuses)
        void unequipWeapon(); // sets current weapon to  “” (removes weapon bonuses)
        

        //getters and setters
        int get_agility();
        void set_agility(int agility);

};

#endif