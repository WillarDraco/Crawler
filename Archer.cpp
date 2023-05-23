#include "Archer.h"
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

Archer::Archer() { // sets all data members to 0 or “”
}

Archer::Archer(int level, std::string name) { // sets strength and health based on level, exp = 0, current weapon = “”;
    this->name = name;
    combat_stats[0] = (level * 10) + 70; // represents the max health of a player
    combat_stats[1] = combat_stats[0]; // current health of player
    combat_stats[2] = 5; // Base attack damage
    combat_stats[3] = 10; // Special attack damage
    combat_stats[4] = 5; // Agility stat
    combat_stats[5] = 1; // Dodge chance
    combat_stats[6] = 2; // Defense stat
    combat_stats[7] = 1; // Crit chance
    combat_stats[8] = 10; // Max ammo
    combat_stats[9] = 10; // Current ammo

    exp = 0;// current experience level
    this->level = level;
    defend = false;
    Weapon** archer_weapon = 0; // currently equipped weapon
}

void Archer::gainExp(int exp) { // Gain exp function after defeating a monster
    int old_level = level;
    this->exp = this->exp + exp;
    level = (1 / 2) * pow((1 / 2),exp);
    if (old_level != level) {
        std::cout << "Congratulations, you have levelled up! \n";
        combat_stats[0] = (level * 10) + 90; // Max Hp
        combat_stats[2] = combat_stats[2] + 2; // Base attack damage
        combat_stats[3] = combat_stats[3] + 10; // Special attack damage
        combat_stats[4] = combat_stats[4] + 5; // Agility stat
        combat_stats[6] = combat_stats[6] + 2; // Defense stat
        combat_stats[8] = combat_stats[8] + 5; // Max ammo
    }
    return;
}

void Archer::equipWeapon(Weapon* archer_weapon) { // sets current weapon (weapon bonuses)
    combat_stats[4] = combat_stats[4] + archer_weapon->get_stat_bonus();
    this->archer_weapon = &archer_weapon;
}

void Archer::unequipWeapon(Weapon* archer_weapon) { // sets current weapon to  “” (removes weapon bonuses)
    combat_stats[4] = combat_stats[4] - archer_weapon->get_stat_bonus();
    this->archer_weapon = 0;
}

void Archer::specialAttack(Monster* monster) { // archer only attack that does damage based on agility and equipped weapon
    int damage = 0;
    if (combat_stats[9] > 0) {
        damage = (combat_stats[4] * ((rand() % 120 + 80) / 100) * level);
        combat_stats[9] = combat_stats[9] - 1;
        if (combat_stats[9] < 0) {
            combat_stats[9] = 0;
        }
        monster->takeDamage(damage);
    } else {
        std::cout << "\nYou dont have enough ammo.\n";
    }
    return;
}

void Archer::rest() { // heals Archer for a turn - based on total health - and increase current ammo by max ammo count
    combat_stats[1] = combat_stats[1] + combat_stats[0] * 0.25;
    if (combat_stats[1] > combat_stats[0]) {
        combat_stats[1] = combat_stats[0];
    }

    std::cout << "You healed " << (combat_stats[0] * 0.25) << " health\n";

    combat_stats[9] = combat_stats[9] + combat_stats[8] * 0.25;
    if (combat_stats[9] > combat_stats[8]) {
        combat_stats[9] = combat_stats[8];
    }

    std::cout << "You gained " << (combat_stats[8] * 0.25) << " ammo\n";
}

int Archer::get_agility() { // Gets agility value
    return combat_stats[4];
}
int Archer::get_max_ammo() { // Gets max ammo value
    return combat_stats[8];
}

int Archer::get_current_ammo() { // Gets current ammo value
    return combat_stats[9];
}

void Archer::set_agility(int agility) { // Sets agility value
    combat_stats[4] = agility;
}

void Archer::set_max_ammo(int max_ammo) { // Gets max ammo value
    combat_stats[8] = max_ammo;
}

void Archer::set_current_ammo(int current_ammo) { // Gets current ammo value
    combat_stats[9] = current_ammo;
}