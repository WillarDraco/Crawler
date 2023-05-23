#include "Archer.h"
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>
#include <string>

Archer::Archer() { // sets all data members to 0 or “”
}

Archer::Archer(int level, std::string name) { // sets strength and health based on level, exp = 0, current weapon = “”;
    this->name = name;
    max_health = (level * 10) + 60; // represents the max health of a player
    current_health = max_health; // current health of player
    exp = 0;// current experience level
    this->level = level;
    defend = false;
    int agility = 5; // represents the agility of a player - affects special attack damage
    Weapon** archer_weapon = 0; // currently equipped weapon
    int max_ammo = 10; // total arrows/bolts knives an archer can have
    int current_ammo = max_ammo; // current ammunition level
}

void Archer::equipWeapon(Weapon* archer_weapon) { // sets current weapon (weapon bonuses)
    agility = agility + archer_weapon->get_stat_bonus();
    this->archer_weapon = &archer_weapon;
}

void Archer::unequipWeapon(Weapon* archer_weapon) { // sets current weapon to  “” (removes weapon bonuses)
    agility = agility - archer_weapon->get_stat_bonus();
    this->archer_weapon = 0;
}

void Archer::special_attack(Monster* monster) { // archer only attack that does damage based on agility and equipped weapon
    int damage = 0;
    if (current_ammo != 0) {
        damage = agility * ((rand() % 10 + 2) * level);
        current_ammo = current_ammo - 1;
    } else {
        std::cout << "No Ammo";
    }
    
    monster->take_damage(damage);
}

void Archer::rest() { // heals player for turn - based on total health
    current_health = current_health + max_health * 0.5;
    if (current_health > max_health) {
        current_health = max_health;
    }
}

int Archer::get_agility() { // Gets agility value
    return agility;
}
int Archer::get_max_ammo() { // Gets max ammo value
    return max_ammo;
}

int Archer::get_current_ammo() { // Gets current ammo value
    return current_ammo;
}

void Archer::set_agility(int agility) { // Sets agility value
    this->agility = agility;
}

void Archer::set_max_ammo(int max_ammo) { // Gets max ammo value
    this->max_ammo = max_ammo;
}

void Archer::set_current_ammo(int current_ammo) { // Gets current ammo value
    this->current_ammo = current_ammo;
}