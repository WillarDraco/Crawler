#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"

class Monster{
    protected:
        int max_health; // represents the max health of a monster
        int current_health; // current health of a monster
        int level; // level of the monster

    public:
        Monster(); //default constructer
        Monster(int level); //sets health based on level

        void punch(); // basic attack
        void defend(); // reduces taken damage for one turn
        virtual void rest(); // heals for turn - based on total health

        virtual void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        virtual void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

        //getters and setters for data members
        int get_max_health();
        int get_current_health();
        int get_level();

        void set_max_health(int);
        void set_current_health(int);
        void set_level(int);

};


#endif