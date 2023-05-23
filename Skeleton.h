#ifndef SKELETON_H
#define SKELETON_H

#include "Monster.h"
#include "Player.h"

class Skeleton : public Monster{
    protected:
        int agility;
        Weapon** skeleton_weapon;

    public:
        Skeleton(Player* player); //default constructor

        void attack(Player* player); //attack

        void equipWeapon(Weapon* skeleton_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* skeleton_weapon); // sets current weapon to  “” (removes weapon bonuses)
        

        //getters and setters
        int get_agility();
        void set_agility(int agility);

};

#endif