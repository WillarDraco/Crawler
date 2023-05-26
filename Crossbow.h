#ifndef CROSSBOW_H
#define CROSSBOW_H
#include "Weapon.h"
#include <string>

class Crossbow : public Weapon {
    public:
        Crossbow(); // Default constructor
        Crossbow(std::string name, int level); // Constructor for a bow
};
#endif