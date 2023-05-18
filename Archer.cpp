#include "Archer.h"
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>

Archer::Archer() { // sets all data members to 0 or “”
}

Archer::Archer(int level) { // sets strength and health based on level, exp = 0, current weapon = “”;
    max_health = (level * 10) + 90; // represents the max health of a player
    current_health = max_health; // current health of player
    exp = 0;// current experience level
    this->level = level;
    defend = false;
    int agility = 5; // represents the agility of a player - affects range damage
    Weapon** archer_weapon = 0; // currently equipped weapon
    int max_ammo = 20; // total arrows/bolts knives an archer can have
    int current_ammo = max_ammo; // current ammunition level
}

void Archer::equipWeapon(Weapon* archer_weapon); // sets current weapon (weapon bonuses)
void Archer::unequipWeapon(Weapon* archer_weapon); // sets current weapon to  “” (removes weapon bonuses)

void Archer::shootWeapon(Monster* monster) { // archer only attack that does damage based on agility and equipped weapon
    int damage = 0;
    if (current_ammo != 0) {
        damage = agility * ((rand() % 10 + 2) * level);
        current_ammo = current_ammo - 1;
    } else {
        std::cout << "No Ammo";
    }

    if (monster->block() == true) {
        damage = damage * 0.85;
        monster->take_damage(damage);
    } else {
        monster->take_damage(damage);
    }
}

void Archer::recoverAmmo() { // recovers a random (small) amount of ammunition
    current_ammo = current_ammo + max_ammo * 0.25;
}

void Archer::rest() { // heals player for turn - based on total health
    current_health = current_health + max_health * 0.5;
    if (current_health > max_health) {
        current_health = max_health;
    }
}