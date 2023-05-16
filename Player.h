#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"

class Player {
    protected:
        int max_health; // represents the max health of a player
        int current_health; // current health of player
        int exp; // current number of experience points
        int level; // total experience level
        int defense; // represents the defense stat of the player
        bool defend; // sets defending state
    public:
        Player(); // default constructor - sets all data members to 0
        Player(int level); // sets level data member, health is set based on level. exp = 0.

        void punch(); // basic attack all players can use
        void defend(int damage); // reduces enemy damage for one turn
        virtual void rest(); // heals player for turn - based on total health
    
        virtual void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        virtual void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

        void take_damage(int damage);
        // getters and setters for all data memebers
        int get_max_health();
        int get_current_health();
        int get_exp();
        int get_level();

        void set_max_health(int health);
        void set_current_health(int health);
        void set_exp(int exp);
        void set_level(int level);
};

#endif