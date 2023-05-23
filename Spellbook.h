#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include "Weapon.h"
#include <string>

class Spellbook : public Weapon {
    public:
        Spellbook(); // Default constructor
        Spellbook(std::string name, int stat_bonus, int level); // Constructor for a bow
};
#endif