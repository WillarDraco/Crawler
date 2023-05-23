#include "Barbarian.h"
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>

Barbarian::Barbarian() { // sets all data members to 0 or “ ”
}

Barbarian::Barbarian(int level, std::string name) { // sets strength and health based on level, exp = 0, current weapon = “”;
    this->name = name;

    combat_stats[0] = (level * 10) + 90; // represents the max health of a player
    combat_stats[1] = combat_stats[0]; // current health of player
    combat_stats[2] = 6; // Base attack damage
    combat_stats[3] = 12; // Special attack damage
    combat_stats[4] = 8; // Represents the strength stat of a barbarian - affects melee damage
    combat_stats[5] = 1; // Dodge chance
    combat_stats[6] = 4; // Defense stat
    combat_stats[7] = 1; // Crit chance

    exp = 0; // current number of experience points
    this->level = level; // total experience level
    defend = false; // sets defending state
    barbarian_weapon = 0;
}

void Barbarian::gainExp(int exp) { // Gain exp function after defeating a monster
    int old_level = level;
    this->exp = this->exp + exp;
    level = (1 / 2) * pow((1 / 2),exp);
    if (old_level != level) {
        std::cout << "Congratulations, you have levelled up! \n";
        combat_stats[0] = (level * 10) + 90; // Max Hp
        combat_stats[2] = combat_stats[2] + 5; // Base attack damage
        combat_stats[4] = combat_stats[4] + 5; // // Represents the strength stat of a barbarian - affects melee damage
        combat_stats[3] = combat_stats[4] + 12; // Special attack damage
        combat_stats[6] = combat_stats[6] + 4; // Defense stat
    }
    return;
}

void Barbarian::equipWeapon(Weapon* barbarian_weapon) { // sets current weapon (weapon bonuses)
    this->barbarian_weapon = &barbarian_weapon;
    combat_stats[0] = combat_stats[0] + barbarian_weapon->get_max_health(); // represents the max health of a player
    combat_stats[1] = combat_stats[1] + barbarian_weapon->get_current_health(); // current health of player
    combat_stats[4] = combat_stats[4] + barbarian_weapon->get_resource_stat(); // Strength stat
    combat_stats[5] = combat_stats[5] + barbarian_weapon->get_dodge_chance(); // Dodge chance
    combat_stats[6] = combat_stats[6] + barbarian_weapon->get_defense(); // Defense stat
    combat_stats[7] = combat_stats[7] + barbarian_weapon->get_crit_chance(); // Crit chance
    combat_stats[3] = combat_stats[3] + combat_stats[4]; // Special attack damage
}

void Barbarian::unequipWeapon(Weapon* barbarian_weapon) { // sets current weapon to  “” (removes weapon bonuses)
    combat_stats[0] = combat_stats[0] + barbarian_weapon->get_max_health(); // represents the max health of a player
    combat_stats[1] = combat_stats[1] + barbarian_weapon->get_current_health(); // current health of player
    combat_stats[4] = combat_stats[4] + barbarian_weapon->get_resource_stat(); // Strength stat
    combat_stats[5] = combat_stats[5] + barbarian_weapon->get_dodge_chance(); // Dodge chance
    combat_stats[6] = combat_stats[6] + barbarian_weapon->get_defense(); // Defense stat
    combat_stats[7] = combat_stats[7] + barbarian_weapon->get_crit_chance(); // Crit chance
    combat_stats[3] = combat_stats[3] + combat_stats[4]; // Special attack damage
    this->barbarian_weapon = 0;
}

void Barbarian::special_attack(Monster* monster) { // barbarian only attack that does damage based on strength
    int damage = (combat_stats[4] * ((rand() % 120 + 80) / 100) * level);
    monster->takeDamage(damage);
}

void Barbarian::rest() { // heals player for turn - based on total health
    combat_stats[1] = combat_stats[1] + combat_stats[0] * 0.35;
    if (combat_stats[1] > combat_stats[0]) {
        combat_stats[1] = combat_stats[0];
    }

    std::cout << "You healed " << (combat_stats[0] * 0.35) << " health\n";
}

int Barbarian::get_strength() { // Gets strength value
    return combat_stats[4];
}

void Barbarian::set_strength(int strength) { // Sets strength value
    combat_stats[4] = strength;
}