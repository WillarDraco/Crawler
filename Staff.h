#ifndef STAFF_H
#define STAFF_H
#include "Weapon.h"
#include <string>

class Staff : public Weapon {
    public:
        Staff(); // Default constructor
        Staff(std::string name, int level); // Constructor for a bow
};
#endif