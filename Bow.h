#ifndef BOW_H
#define BOW_H
#include "Weapon.h"
#include <string>

class Bow : public Weapon {
    public:
        Bow(); // Default constructor
        Bow(std::string name, int stat_bonus, int level); // Constructor for a bow
};
#endif