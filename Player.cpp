#include "Player.h"
#include <iostream>

Player::Player() { // default constructor - sets all data members to 0
}
Player::Player(int level) { // sets level data member, health is set based on level. exp = 0.
    max_health = (level * 10) + 90; // represents the max health of a player
    current_health = max_health; // current health of player
    exp = 0;// current experience level
    this->level = level;
}

void Player::punch() { // basic attack all players can use
    int damage = level / 2 * 5;
    enemy.setHealth(maxHealth - damage);    
}
void Player::defend(); // reduces enemy damage for one turn

// getters and setters for all data memebers
int Player::get_max_health();
int Player::get_current_health();
int Player::get_experience();
int Player::get_level();

void Player::set_max_health();
void Player::set_current_health();
void Player::set_experience();
void Player::set_level();