#include "Spellbook.h"
#include <string>

Spellbook::Spellbook() { // Default constructor
}

Spellbook::Spellbook(std::string name, int stat_bonus, int level) { // Constructor for a bow
    this->level = level;
    this->name = name;
    this->stat_bonus = stat_bonus * level;
}