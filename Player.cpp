#include "Player.h"
#include "Enemy.h"
#include <iostream>

Player::Player() { // default constructor - sets all data members to 0
}

Player::Player(int level) { // sets level data member, health is set based on level. exp = 0.
    max_health = (level * 10) + 90; // represents the max health of a player
    current_health = max_health; // current health of player
    exp = 0;// current experience level
    this->level = level;
    defense = 10;
    defend = false;
}

void Player::punch() { // basic attack all players can use
    int damage = level / 2 * 5;
    if (enemy.defend() = true) {
        damage = 
    } else {
        enemy.take_damage(damage);
    }
}
void Player::defend() { // reduces enemy damage for one turn
    defend = true;
}

void take_damage(int damage) {
    current_health = current_health - damage;
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

void Player::set_max_health(int health) { // Sets max health
    max_health = health;
}

void Player::set_current_health(int health) { // Sets health
    current_health = health;
}

void Player::set_exp(int exp) { // Sets exp
    this->exp = exp
}

void Player::set_level() { //Sets level
    this->level = level;
}