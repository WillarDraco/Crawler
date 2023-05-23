#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"
#include <vector>

class Player; // forward declaration to avoid codependecy

class Monster{
    protected:
        std::vector<int> combat_stats;
        int level; // level of the monster
        bool defend; //sets defending state

    public:
        Monster(); //default constructer
        Monster(Player* player); //sets health based on level

        virtual void attack(Player* player); // basic attack
        virtual void block(); // reduces taken damage for one turn
        virtual void takeDamage(int damage); //taking damage from player
        virtual bool hasBlocked(); //check if monster has blocked

        virtual void equipWeapon(Weapon* weapon); // sets current weapon (weapon bonuses)
        virtual void unequipWeapon(Weapon* weapon); // sets current weapon to  “” (removes weapon bonuses)
        
        
        //getters and setters for data members
        std::vector<int> get_combat_stats();
        int get_max_health();
        int get_current_health();
        int get_level();

        void set_max_health(int health);
        void set_current_health(int health);
        void set_level(int level);

};
#endif