#ifndef MACE_H
#define MACE_H
#include "Weapon.h"
#include <string>

class Mace : public Weapon {
    public:
        Mace(); // Default constructor
        Mace(std::string name, int level); // Constructor for a bow
};
#endif