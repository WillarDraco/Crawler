#include "Bow.h"
#include <string>

Bow::Bow() { // Default constructor
}

Bow::Bow(std::string name, int stat_bonus) { // Constructor for a dagger
    this->name = name;
    this->stat_bonus = stat_bonus;
}