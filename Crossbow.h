#ifndef CROSSBOW_H
#define CROSSBOW_H
#include "Weapon.h"
#include <string>

class Crossbow : protected Weapon {
    public:
        Crossbow(); // Default constructor
        Crossbow(std::string name, int stat_bonus, int level); // Constructor for a bow
};
#endif