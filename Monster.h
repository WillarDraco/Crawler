#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"

class Monster{
    protected:
        int max_health; // represents the max health of a monster
        int current_health; // current health of a monster
        int level; // level of the monster
        bool defend; //sets defending state
        int exp;

    public:
        Monster(); //default constructer
        Monster(Player* player); //sets health based on level

        virtual void punch(Player* player); // basic attack
        virtual bool block(); // reduces taken damage for one turn
        virtual void take_damage(int damage); //taking damage from player

        virtual void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        virtual void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

        //getters and setters for data members
        int get_max_health();
        int get_current_health();
        int get_level();

        void set_max_health(int health);
        void set_current_health(int health);
        void set_level(int level);

};
#endif