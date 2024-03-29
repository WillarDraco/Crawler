#include "BattleAxe.h"
#include <string>

Battleaxe::Battleaxe(){}; // Default constructor

Battleaxe::Battleaxe(std::string name, int level) { // Constructor for a bow
    this->level = level;
    this->name = name;
    weapon_stats[0] = level * 5; // represents the max health increase
    weapon_stats[1] = level * 5; // current health increase
    weapon_stats[4] = level * 5; // Strength increase
    weapon_stats[5] = level * 0; // Dodge chance increase
    weapon_stats[6] = level * 5; // Defense stat increase
    weapon_stats[7] = level * 3; // Crit chance increase
    weapon_stats[8] = level * 0; // Max ammo increase
    weapon_stats[9] = level * 0; // Current ammo increase
}