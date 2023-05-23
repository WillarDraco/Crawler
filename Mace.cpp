#include "Mace.h"
#include <string>

Mace::Mace() { // Default constructor
}

Mace::Mace(std::string name, int stat_bonus, int level) { // Constructor for a bow
    this->level = level;
    this->name = name;
    this->stat_bonus = stat_bonus * level;
}