#include "Barbarian.h"
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"
#include <cstdlib>
#include <string>
#include <iostream>

Barbarian::Barbarian() { // sets all data members to 0 or “ ”
}

Barbarian::Barbarian(int level, std::string name) { // sets strength and health based on level, exp = 0, current weapon = “”;
    this->name = name;
    max_health = (level * 10) + 100; // represents the max health of a player
    current_health = max_health; // current health of player
    exp = 0; // current number of experience points
    this->level = level; // total experience level
    defend = false; // sets defending state
    strength = ((level * 10) / 2); // represents the strength stat of a barbarian - affects melee damage
}

//void Barbarian::equipWeapon(Weapon* barbarian_weapon); // sets current weapon (weapon bonuses)
//void Barbarian::unequipWeapon(Weapon* barbarian_weapon); // sets current weapon to  “” (removes weapon bonuses)

void Barbarian::special_attack(Monster* monster) { // barbarian only attack that does damage based on strength and equipped weapon
    int damage = strength * ((rand() % 5) * level);
    if (monster->hasBlocked() == true) {
            damage = damage * 0.85;
            monster->take_damage(damage);
        } else {
            monster->take_damage(damage);
    }
}

void Barbarian::rest() { // heals player for turn - based on total health
    current_health = current_health + max_health * 0.5;
    if (current_health > max_health) {
        current_health = max_health;
    }
}

int Barbarian::get_strength() { // Gets strength value
    return strength;
}

void Barbarian::set_strength(int strength) { // Sets strength value
    this->strength = strength;
}

void Barbarian::attack(Monster* monster) { // basic attack all players can use
    int damage = get_level() / 2 * 5;
    if (monster->hasBlocked() == true) {
        damage = damage * 0.85;
        std::cout << "You did " << damage << " damage\n";
        monster->take_damage(damage);
        std::cout << "The monster has " << monster->get_current_health() << " health left\n";
    } else {
        std::cout << "You did " << damage << " damage\n";
        monster->take_damage(damage);
        std::cout << "The monster has " << monster->get_current_health() << " health left\n";
    }
}