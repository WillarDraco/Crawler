#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
    protected:
        std::string name; // represents name of player’s weapon
        int stat_bonus; // represents bonus strength/mana/agility of weapon

    public:
        Weapon(); // default constructor sets name to “” and stat bonus to 0
        Weapon(char name, int stat_bonus); // constructor setting name and stat bonus
        std::string get_name(); // Gets the name
        int get_stat_bonus(); // Gets the stat bonus
        void set_name(std::string name); // Sets the name 
        void set_stat_bonus(int stat_bonus); // Sets the stat bonus
};
#endif