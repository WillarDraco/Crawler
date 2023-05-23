#include "Dagger.h"
#include <string>

Dagger::Dagger() { // Default constructor
}

Dagger::Dagger(std::string name, int stat_bonus, int level) { // Constructor for a dagger
    this->level = level;
    this->name = name;
    this->stat_bonus = stat_bonus * level;
}
