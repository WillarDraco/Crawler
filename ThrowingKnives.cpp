#include "ThrowingKnives.h"
#include <string>

ThrowingKnives::ThrowingKnives() { // Default constructor
}

ThrowingKnives::ThrowingKnives(std::string name, int stat_bonus, int level) { // Constructor for a bow
    this->level = level;
    this->name = name;
    this->stat_bonus = stat_bonus * level;
}