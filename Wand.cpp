#include "Wand.h"
#include <string>

Wand::Wand() { // Default constructor
}

Wand::Wand(std::string name, int stat_bonus, int level) { // Constructor for a Wand
    this->level = level;
    this->name = name;
    this->stat_bonus = stat_bonus * level;
}