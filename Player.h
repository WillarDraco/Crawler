#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"

class Player {
    protected:
        int max_health; // represents the max health of a player
        int current_health; // current health of player
        int exp; // current experience level
        int level; // total experience level
    public:
        Player(); // default constructor - sets all data members to 0
        Player(int level); // sets level data member, health is set based on level. exp = 0.

        void punch(); // basic attack all players can use
        void defend(); // reduces enemy damage for one turn
        virtual void rest(); // heals player for turn - based on total health

        virtual void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        virtual void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

        // getters and setters for all data memebers
        int get_max_health();
        int get_current_health();
        int get_experience();
        int get_level();

        void set_max_health();
        void set_current_health();
        void set_experience();
        void set_level();


};

#endif