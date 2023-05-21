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

};

#endif