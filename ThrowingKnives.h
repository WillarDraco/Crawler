#ifndef THROWINGKNIVES_H
#define THROWINGKNIVES_H
#include "Weapon.h"
#include <string>

class ThrowingKnives : public Weapon {
    public:
        ThrowingKnives(); // Default constructor
        ThrowingKnives(std::string name, int stat_bonus, int level); // Constructor for a bow
};
#endif