#include "Player.h"
#include <iostream>
#include <cmath>
#include "Monster.h"

Player::Player() { // default constructor - sets all data members to 0
}

Player::Player(int level) { // sets level data member, health is set based on level. exp = 0.
    exp = 0;// current experience level
    this->level = level;
    defend = false;
    combat_stats = {100, 100, 5, 10, 0, 5, 1, 0}; // Stats {max_hp (0), current_hp (1), damage(2), special damage(3), dodge chance()4, defense(5), crit chance(6), resource_modifier(7)}
}

void Player::attack(Monster* monster) { // basic attack all players can use
    monster->take_damage(combat_stats[2]);
}

void Player::special_attack(Monster* monster) { // special attack for each class
    monster->take_damage(combat_stats[3]);
}

void Player::equipWeapon(Weapon* weapon) { // sets current weapon (weapon bonuses)
}

void Player::unequipWeapon(Weapon* weapon) { // sets current weapon to  “” (removes weapon bonuses)
}

void Player::block() { // reduces damage taken for one turn
    defend = true;
}

void Player::take_damage(int damage) {
    if (defend == true) {
        std::cout << "\nYou blocked the monster's attack.\n";
        return;
    } else if (defend == false) {
        combat_stats[1] = combat_stats[1] - damage;
        std::cout << "\nThe monster attacked for " << damage << "damage\n";
        std::cout << "You have " << combat_stats[1] << " health left\n";
        return;
    }
}

void Player::gain_exp(int exp) { // Gain exp function after defeating a monster
    int old_level = level;
    this->exp = this->exp + exp;
    level = (1 / 2) * pow((1 / 2),exp);
    if (old_level != level) {
        std::cout << "Congratulations, you have levelled up! \n";
        combat_stats[0] = (level * 10) + 90;
        combat_stats[2] = combat_stats[2] + 5;
        combat_stats[3] = combat_stats[3] + 10;
        combat_stats[5] = combat_stats[5] + 5;
    }
    return;
}

// getters and setters for all data memebers
int Player::get_max_health() { // Gets max health
    return max_health;
}

int Player::get_current_health() { // Gets current health
    return current_health;
}

int Player::get_exp() { // Gets current exp
    return exp;
}

int Player::get_level() { //Gets current level
    return level;
}

std::string Player::get_name() { //gets player name
    return name;
}

void Player::set_max_health(int health) { // Sets max health
    max_health = health;
    return;
}

void Player::set_current_health(int health) { // Sets health
    current_health = health;
    return;
}

void Player::set_exp(int exp) { // Sets exp
    this->exp = exp;
    return;
}

void Player::set_level(int level) { //Sets level
    this->level = level;
    return;
}