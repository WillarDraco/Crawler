#include "Player.h"
#include <iostream>
#include <cmath>
#include "Monster.h"
#include <fstream>
#include <string>

Player::Player() { // default constructor - sets all data members to 0
}

Player::Player(int level) { // sets level data member, health is set based on level. exp = 0.
    exp = 0;// current experience level
    this->level = level;
    defend = false;
    // Stats {max_hp (0), current_hp (1), damage(2), special damage(3), class stat(4), dodge chance(5), defense(6), crit chance(7), max resource(8), current resource (9)}
    combat_stats[0] = 100;
    combat_stats[1] = 100;
    combat_stats[2] = 5;
    combat_stats[3] = 10;
    combat_stats[4] = 0;
    combat_stats[5] = 5;
    combat_stats[6] = 1;
    combat_stats[7] = 0;
    combat_stats[8] = 1;
    combat_stats[9] = 0;
    
    boss_kill_count = 0;
    standard_kill_count = 0;
}

void Player::attack(Monster* monster) { // basic attack all players can use
    int damage = combat_stats[2] * (((rand() % 120) + 80) / 100);
    monster->takeDamage(damage);
}

void Player::specialAttack(Monster* monster) { // special attack for each class
    monster->takeDamage(combat_stats[3]);
}

void Player::equipWeapon(Weapon* weapon) { // sets current weapon (weapon bonuses)
}

void Player::unequipWeapon(Weapon* weapon) { // sets current weapon to  “” (removes weapon bonuses)
}

void Player::block() { // reduces damage taken for one turn
    defend = true;
}

void Player::takeDamage(int damage) {
    damage = damage - combat_stats[6];
    if (damage < 0){
        damage = 0;
    }
    int dodge = combat_stats[5] * (rand() % 100);
    if (defend == true) {
        std::cout << "\nYou blocked the monster's attack.\n";
        return;
    } else if (defend == false) {
        if (dodge >= 84 ) {
            std::cout << "\nThe attack missed!\n";
            return;
        } else if (dodge < 84) {
            combat_stats[1] = combat_stats[1] - damage;
            std::cout << "\nThe monster attacked for " << damage << " damage\n";
            std::cout << "You have " << combat_stats[1] << " health left\n";
            return;
        }
    }
}

void Player::rest() {
    combat_stats[1] = combat_stats[1] + combat_stats[0] *0.1;
}

void Player::gainExp(int exp) { // Gain exp function after defeating a monster
    int old_level = level;
    this->exp = this->exp + exp;
    level = (1 / 2) * pow((1 / 2),exp);
    if (old_level != level) {
        std::cout << "Congratulations, you have levelled up! \n";
        combat_stats[0] = (level * 10) + 90; // Max Hp
        combat_stats[2] = combat_stats[2] + 5; // Base attack damage
        combat_stats[3] = combat_stats[3] + 10; // Special attack damage
        combat_stats[4] = combat_stats[4] + 5;
        combat_stats[5] = combat_stats[5] + 5;
        combat_stats[8] = combat_stats[8] + 10;
    }
    return;
}

void Player::increaseBossKillCount() {
    this->boss_kill_count++;
}

void Player::increaseStandardKillCount() {
    this->standard_kill_count++;
}

// getters and setters for all data memebers
int* Player::get_combat_stats() {
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

int Player::get_class_stat(){
    return combat_stats[4];
}

int Player::get_dodge_chance() {
    return combat_stats[5];
}

int Player::get_defense() {
    return combat_stats[6];
}

int Player::get_crit_chance() {
    return combat_stats[7];
}

int Player::get_current_resource() {
    return combat_stats[9];
}

int Player::get_max_resource() {
    return combat_stats[8];
}

int Player::get_boss_kill_count() {
    return boss_kill_count;
}

int Player::get_standard_kill_count() {
    return standard_kill_count;
}

void Player::set_max_health(int health) { // Sets max health
    combat_stats[0] = health;
    return;
}

void Player::set_current_health(int health) { // Sets health
    combat_stats[1] = health;
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

void Player::set_class_stat(int class_stat){
    combat_stats[4] = class_stat;
}

void Player::set_dodge_chance(int dodge) {
    combat_stats[5] = dodge;
}

void Player::set_defense(int defense) {
    combat_stats[6] = defense;
}

void Player::set_crit_chance(int crit) {
    combat_stats[7] = crit;
}

void Player::set_current_resource(int resource) {
    combat_stats[9] = resource;
}

void Player::set_max_resource(int resource) {
    combat_stats[8] = resource;
}

void Player::set_boss_kill_count(int boss_kill_count) {
    this->boss_kill_count = boss_kill_count;
}

void Player::set_standard_kill_count(int standard_kill_count) {
    this->standard_kill_count = standard_kill_count;
}

void Player::save(Player* current_player) {
    std::ofstream savefile("savefile.txt", std::ios::trunc);

    savefile.open("savefile.txt");
    
    savefile.write((char*)&current_player, sizeof(Player));

    savefile.close();
    
}

void Player::load() {
    Player save_player;
    std::fstream savefile("savefile.txt", std::ios::in);
    savefile.open("savefile.txt");

    savefile.read((char*)&save_player, sizeof(Player));

    savefile.close();
    this->name = save_player.get_name();
    this->level = save_player.get_level();
    
    this->exp = save_player.get_exp();

}

