#include "BattleAxe.h"
#include <string>

Battleaxe::Battleaxe() { // Default constructor
}

Battleaxe::Battleaxe(std::string name, int stat_bonus, int level) { // Constructor for a bow
    this->level = level;
    this->name = name;
    this->stat_bonus = stat_bonus * level;
}