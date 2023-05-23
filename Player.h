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
        virtual void specialAttack(Monster* monster); // special attack for each class
        void block(); // reduces enemy damage for one turn
        virtual void rest(); // heals player for turn - based on total health
    
        virtual void equipWeapon(Weapon* weapon); // sets current weapon (weapon bonuses)
        virtual void unequipWeapon(Weapon* weapon); // sets current weapon to  “” (removes weapon bonuses)

        void takeDamage(int damage); // Take damage function
        virtual void gainExp(int exp); // Gain exp function after defeating a monster
        //virtual void level_up(); // Changes stats according to level

        // getters and setters for all data memebers
        std::vector<int> get_combat_stats();
        int get_max_health();
        int get_current_health();
        int get_exp();
        int get_level();
        std::string get_name();
        int get_damage();
        int get_special_damage();
        int get_dodge_chance();
        int get_defense();
        int get_crit_chance();
        int get_current_resource();
        int get_max_resource();

        void set_max_health(int health);
        void set_current_health(int health);
        void set_exp(int exp);
        void set_level(int level);
        void set_name(std::string name);
        void set_damage(int damage);
        void set_special_damage(int special);
        void set_dodge_chance(int dodge);
        void set_defense(int defense);
        void set_crit_chance(int crit);
        void set_current_resource(int resource);
        void set_max_resource(int resource);
};
#endif