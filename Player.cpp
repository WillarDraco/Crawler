#include "Player.h"
#include <iostream>
#include <cmath>
#include "Monster.h"

Player::Player() { // default constructor - sets all data members to 0
}

Player::Player(int level) { // sets level data member, health is set based on level. exp = 0.
    max_health = (level * 10) + 90; // represents the max health of a player
    current_health = max_health; // current health of player
    exp = 0;// current experience level
    this->level = level;
    defend = false;
}

void Player::attack(Monster* monster) { // basic attack all players can use
    int damage = level * 5;
    if (monster->hasBlocked() == true) {
        damage = damage * 0.85;
        std::cout << "\nYou did " << damage << " damage\n";
        monster->take_damage(damage);
    } else {
        std::cout << "\nYou did " << damage << " damage\n";
        monster->take_damage(damage);
    }
}

//void special_attack(Monster* monster) { // special attack for each class
//}

void Player::block() { // reduces damage taken for one turn
    defend = true;
}

void Player::take_damage(int damage) {
    current_health = current_health - damage;
    std::cout << "You have " << current_health << " health left\n";
}

void Player::gain_exp(Monster* monster) { // Gain exp function after defeating a monster
    int old_level = level;
    exp = exp + ((1 /3) * level) * (((rand() % 120) + 80) / 100);
    level = (1 / 2) * pow((1 / 2),exp);
    if (old_level != level) {
        std::cout << "Congratulations, you have levelled up! \n";
        max_health = (level * 10) + 90;
    }
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
}

void Player::set_current_health(int health) { // Sets health
    current_health = health;
}

void Player::set_exp(int exp) { // Sets exp
    this->exp = exp;
}

void Player::set_level(int level) { //Sets level
    this->level = level;
}