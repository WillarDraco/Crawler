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
    combat_stats = {100, 100, 5, 10, 0, 5, 1, 0, 10}; // Stats {max_hp (0), current_hp (1), damage(2), special damage(3), dodge chance()4, defense(5), crit chance(6), current resource(7), max resource (8)}
}

void Player::attack(Monster* monster) { // basic attack all players can use
    monster->takeDamage(combat_stats[2]);
}

void Player::special_attack(Monster* monster) { // special attack for each class
    monster->takeDamage(combat_stats[3]);
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
std::vector<int> Player::get_combat_stats() {
    return combat_stats;
}

int Player::get_max_health() { // Gets max health
    return combat_stats[0];
}

int Player::get_current_health() { // Gets current health
    return combat_stats[1];
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

int Player::get_damage() {
    return combat_stats[2];
}

int Player::get_special_damage() {
    return combat_stats[3];
}

int Player::get_dodge_chance() {
    return combat_stats[4];
}

int Player::get_defense() {
    return combat_stats[5];
}

int Player::get_crit_chance() {
    return combat_stats[6];
}

int Player::get_current_resource() {
    return combat_stats[7];
}

int Player::get_max_resource() {
    return combat_stats[8];
}

void Player::set_max_health(int health) { // Sets max health
    combat_stats[0] = health;
    return;
}

void Player::set_current_health(int health) { // Sets health
    combat_stats[0] = health;
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

void Player::set_damage(int damage) {
    combat_stats[2] = damage;
}

void Player::set_special_damage(int special) {
    combat_stats[3] = special;
}

void Player::set_dodge_chance(int dodge) {
    combat_stats[4] = dodge;
}

void Player::set_defense(int defense) {
    combat_stats[5] = defense;
}

void Player::set_crit_chance(int crit) {
    combat_stats[6] = crit;
}

void Player::set_current_resource(int resource) {
    combat_stats[7] = resource;
}

void Player::set_max_resource(int resource) {
    combat_stats[8] = resource;
}