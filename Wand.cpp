#include "Wand.h"
#include <string>

Wand::Wand() { // Default constructor
}

Wand::Wand(std::string name, int stat_bonus) { // Constructor for a dagger
    this->name = name;
    this->stat_bonus = stat_bonus;
}