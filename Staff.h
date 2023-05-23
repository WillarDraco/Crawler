#ifndef STAFF_H
#define STAFF_H
#include "Weapon.h"
#include <string>

class Staff : protected Weapon {
    public:
        Staff(); // Default constructor
        Staff(std::string name, int stat_bonus, int level); // Constructor for a bow
};
#endif