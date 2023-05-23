#include "Bow.h"
#include <string>

Bow::Bow() { // Default constructor
}

Bow::Bow(std::string name, int stat_bonus, int level) { // Constructor for a bow
    this->level = level;
    this->name = name;
    this->stat_bonus = stat_bonus * level;
}