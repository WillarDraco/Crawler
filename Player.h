#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include <string>
#include <vector>

class Monster; // forward declaration to avoid codependecy

class Player {
    protected:
        int exp; // current number of experience points
        int level; // total experience level
        bool defend; // sets defending state
        std::string name; // players name
        std::vector<int> combat_stats; // Array to hold combat stats
    public:
        Player(); // default constructor - sets all data members to 0
        Player(int level); // sets level data member, health is set based on level. exp = 0.

        void attack(Monster* monster); // basic attack all players can use
        virtual void special_attack(Monster* monster); // special attack for each class
        void block(); // reduces enemy damage for one turn
        virtual void rest(); // heals player for turn - based on total health
    
        virtual void equipWeapon(Weapon* weapon); // sets current weapon (weapon bonuses)
        virtual void unequipWeapon(Weapon* weapon); // sets current weapon to  “” (removes weapon bonuses)

        void take_damage(int damage); // Take damage function
        void gain_exp(int exp); // Gain exp function after defeating a monster
        //virtual void level_up(); // Changes stats according to level

        // getters and setters for all data memebers
        int get_max_health();
        int get_current_health();
        int get_exp();
        int get_level();
        std::string get_name();

        void set_max_health(int health);
        void set_current_health(int health);
        void set_exp(int exp);
        void set_level(int level);
        void set_name(std::string name);
};
#endif