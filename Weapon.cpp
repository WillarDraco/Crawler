#include "Weapon.h"
#include <string>

Weapon::Weapon() { // default constructor sets name to “” and stat bonus to 0
}

Weapon::Weapon(std::string name, int level) { // constructor setting level, name and stat bonus
    this->level = level;
    this->name = name;

    weapon_stats[0] = 10; // represents the max health of a player
    weapon_stats[1] = weapon_stats[0]; // current health of player
    weapon_stats[2] = 5; // Base attack damage
    weapon_stats[3] = 10; // Special attack damage
    weapon_stats[4] = 5; // Resource stat
    weapon_stats[5] = 1; // Dodge chance
    weapon_stats[6] = 2; // Defense stat
    weapon_stats[7] = 1; // Crit chance
}

// getters and setters for all data memebers
std::vector<int> Weapon::get_weapon_stats() {
    return weapon_stats;
}

int Weapon::get_max_health() { // Gets max health
    return weapon_stats[0];
}

int Weapon::get_current_health() { // Gets current health
    return weapon_stats[1];
}

int Weapon::get_level() { // Gets current level
    return level;
}

std::string Weapon::get_name() { // Gets weapon name
    return name;
}

int Weapon::get_damage() { // Gets base damage
    return weapon_stats[2];
}

int Weapon::get_special_damage() { // Gets special damage
    return weapon_stats[3];
}

int Weapon::get_resource_stat() { // Gets resource stat
    return weapon_stats[4];
}

int Weapon::get_dodge_chance() { // Gets dodge chance
    return weapon_stats[5];
}

int Weapon::get_defense() { // Gets defense stat
    return weapon_stats[6];
}

int Weapon::get_crit_chance() { // Gets crit chance
    return weapon_stats[7];
}

void Weapon::set_max_health(int health) { // Sets max health
    weapon_stats[0] = health;
    return;
}

void Weapon::set_current_health(int health) { // Sets health
    weapon_stats[1] = health;
    return;
}

void Weapon::set_level(int level) { //Sets level
    this->level = level;
    return;
}

void Weapon::set_damage(int damage) { // Sets base damage
    weapon_stats[2] = damage;
}

void Weapon::set_special_damage(int special) { // Sets special damage
    weapon_stats[3] = special;
}

void Weapon::set_resource_stat(int recource) { // Gets resource stat
    weapon_stats[4] = recource;
}

void Weapon::set_dodge_chance(int dodge) { // Sets dodge chance
    weapon_stats[5] = dodge;
}

void Weapon::set_defense(int defense) { // Sets defense stat
    weapon_stats[6] = defense;
}

void Weapon::set_crit_chance(int crit) { // Sets crit chance
    weapon_stats[7] = crit;
}