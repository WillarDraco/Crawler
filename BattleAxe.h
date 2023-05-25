#ifndef BATTLEAXE_H
#define BATTLEAXE_H
#include "Weapon.h"
#include <string>

class Battleaxe : public Weapon {
    public:
        Battleaxe(); // Default constructor
        Battleaxe(std::string name, int leve); // Constructor for a bow
};
#endif