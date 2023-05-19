#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"
#include "Player.h"

class Skeleton : public Monster{
    protected:
        int agility;

    public:
        Skeleton(int level); //default constructor

        void range_attack(Player* player); // range attack


        void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)
        

        //getters and setters
        int get_agility();
        void set_agility(int agility);

};

#endif