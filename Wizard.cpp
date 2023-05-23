#include "Wizard.h"
#include "Monster.h"
#include <cstdlib>
#include <iostream>
#include <string>

Wizard::Wizard() { // sets all data members to 0 or “ ”
}

Wizard::Wizard(int level, std::string name) { // sets mana and health based on level, exp = 0, current weapon = “”, name is inherited;
    this->name = name;
    max_health = (level * 10) + 70; // represents the max health of a player
    current_health = max_health; // current health of player
    exp = 0; // current number of experience points
    this->level = level; // total experience level
    defend = false; // sets defending state
    max_mana = (level * 10) + 90; // represents the maximum mana of a player - affects magic damage and usage
    current_mana = max_mana; // current mana level of player
    wizard_weapon = 0;
}

void Wizard::equipWeapon(Weapon* wizard_weapon) { // sets current weapon (weapon bonuses)
    max_mana = max_mana + wizard_weapon->get_stat_bonus();
    this->wizard_weapon = &wizard_weapon;
}

void Wizard::unequipWeapon(Weapon* wizard_weapon) { // sets current weapon to  “” (removes weapon bonuses)
    max_mana = max_mana - wizard_weapon->get_stat_bonus();
    this->wizard_weapon = 0;
}

void Wizard::special_attack(Monster* monster) { // wizard only attack that uses mana and does damage based on mana and equipped weapon
    int damage = (max_mana / 90)* ((rand() % 5) * level);
    current_mana = max_mana - 10;
    monster->take_damage(damage);
    std::cout << "user used fireball. It did " << damage << ".\n";
}

void Wizard::rest() { // heals player and recharges mana for turn - based on total health and mana
    current_health = current_health + max_health * 0.25;
    if (current_health > max_health) {
        current_health = max_health;
    }
    
    current_mana = current_mana + max_mana * 0.25;
    if (current_mana > max_mana) {
        current_mana = max_mana;
    }
}

int Wizard::get_max_mana() { // Gets max mana
    return max_mana;
}

int Wizard::get_current_mana() { // Gets current mana
    return current_mana;
}

void Wizard::set_max_mana(int mana) { // Sets max mana
    max_mana = mana;
}

void Wizard::set_current_mana(int mana) { // Sets current mana
    current_mana = mana;
}