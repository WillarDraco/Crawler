#include "Wizard.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

Wizard::Wizard() { // sets all data members to 0 or “ ”
}

Wizard::Wizard(int level, std::string name) { // sets mana and health based on level, exp = 0, current weapon = “”, name is inherited;
    this->name = name;

    combat_stats[0] = (level * 10) + 50; // represents the max health of a player
    combat_stats[1] = combat_stats[0]; // current health of player
    combat_stats[2] = 2; // Base attack damage
    combat_stats[3] = 10; // Special attack damage
    combat_stats[4] = 100; // Represents the maximum mana of a player - affects magic damage and usage
    combat_stats[5] = 1; // Dodge chance
    combat_stats[6] = 2; // Defense stat
    combat_stats[7] = 1; // Crit chance
    combat_stats[8] = combat_stats[4]; // current mana level of player

    exp = 0; // current number of experience points
    this->level = level; // total experience level
    defend = false; // sets defending state
    wizard_weapon = 0;
}

void Wizard::gainExp(int exp) { // Gain exp function after defeating a monster
    int old_level = level;
    this->exp = this->exp + exp;
    level = (1 / 2) * pow((1 / 2),exp);
    if (old_level != level) {
        std::cout << "\nCongratulations, you have levelled up!\n";
        combat_stats[0] = combat_stats[0] + 10; // Max Hp
        combat_stats[2] = combat_stats[2] + 2; // Base attack damage
        combat_stats[4] = combat_stats[4] + 5; // Represents the maximum mana of a player - affects magic damage and usage
        combat_stats[3] = combat_stats[4] + 10; // Special attack damage
        combat_stats[6] = combat_stats[6] + 2; // Defense stat
    }
    return;
}

void Wizard::equipWeapon(Weapon* wizard_weapon) { // sets current weapon (weapon bonuses)
    combat_stats[4] = combat_stats[4] + wizard_weapon->get_stat_bonus();
    this->wizard_weapon = &wizard_weapon;
}

void Wizard::unequipWeapon(Weapon* wizard_weapon) { // sets current weapon to  “” (removes weapon bonuses)
    combat_stats[4] = combat_stats[4] - wizard_weapon->get_stat_bonus();
    this->wizard_weapon = 0;
}

void Wizard::specialAttack(Monster* monster) { // wizard only attack that uses mana and does damage based on mana and equipped weapon
    int damage = 0;
    if (combat_stats[8] > 0) {
        damage = ((combat_stats[4] / 90) * ((rand() % 120 + 80) / 100) * level);
        combat_stats[8] = combat_stats[8] - 10;
        if (combat_stats[8] < 0) {
            combat_stats[8] = 0;
        }
        monster->takeDamage(damage);
    } else if (combat_stats[8] <= 0) {
        std::cout << "\nYou don't have enough mana.\n";
    }
    return;
}

void Wizard::rest() { // heals player and recharges mana for turn - based on total health and mana
    combat_stats[1] = combat_stats[1] + combat_stats[0] * 0.25;
    if (combat_stats[1] > combat_stats[0]) {
        combat_stats[1] = combat_stats[0];
    }
    
    combat_stats[8] = combat_stats[8] + combat_stats[4] * 0.25;
    if (combat_stats[8] > combat_stats[4]) {
        combat_stats[8] = combat_stats[4];
    }
}

int Wizard::get_max_mana() { // Gets max mana
    return combat_stats[4];
}

int Wizard::get_current_mana() { // Gets current mana
    return combat_stats[8];
}

void Wizard::set_max_mana(int mana) { // Sets max mana
    combat_stats[4] = mana;
}

void Wizard::set_current_mana(int mana) { // Sets current mana
    combat_stats[8] = mana;
}