#include "Weapon.h"
#include <string>

std::string Weapon::get_name() { // Gets name of the weapon
    return name;
}

int Weapon::get_stat_bonus() { // Gets the stat bonus
    return stat_bonus;
}

void Weapon::set_name(std::string name) { // Sets name of the weapon
    this->name = name;
}

void Weapon::set_stat_bonus(int stat_bonus) { // Sets the stat bonus
    this->stat_bonus = stat_bonus;
}