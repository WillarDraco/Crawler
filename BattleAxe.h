#ifndef BATTLEAXE_H
#define BATTLEAXE_H
#include "Weapon.h"
#include <string>

class Battleaxe : protected Weapon {
    public:
        Battleaxe(); // Default constructor
        Battleaxe(std::string name, int stat_bonus, int level); // Constructor for a bow
};
#endif