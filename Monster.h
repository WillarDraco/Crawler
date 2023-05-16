#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"

class Monster{
    protected:
        int max_health; // represents the max health of a monster
        int current_health; // current health of a monster
        int level; // level of the monster
        bool defend; //sets defending state

    public:
        Monster(); //default constructer
        Monster(int level); //sets health based on level

        virtual void attack(Player* player); // basic attack
        virtual bool block(); // reduces taken damage for one turn
        virtual void take_damage(int damage); //taking damage from player

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