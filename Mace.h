#ifndef MACE_H
#define MACE_H
#include "Weapon.h"
#include <string>

class Mace : protected Weapon {
    public:
        Mace(); // Default constructor
        Mace(std::string name, int stat_bonus, int level); // Constructor for a bow
};
#endif