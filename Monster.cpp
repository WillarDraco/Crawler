#include "Monster.h"
#include "Weapon.h"
#include "Player.h"
#include <cstdlib>
#include <iostream>
    
    //default constructer sets everything to basics
    Monster::Monster() {}; 

    //set health based on level
    Monster::Monster(Player* player){
        level = player->get_level();

        max_health = 20 + 5*(level);
        current_health = max_health;

        defend = false;    
        };

    // basic attack
    void Monster::punch(Player* player){}

    void Monster::equipWeapon(Weapon* weapon) { // sets current weapon (weapon bonuses)
    max_health = max_health + weapon->get_stat_bonus();
    }

    void Monster::unequipWeapon(Weapon* weapon) { // sets current weapon to  “” (removes weapon bonuses)
    max_health = max_health + weapon->get_stat_bonus();
    }

    // reduces taken damage for one turn
    void Monster::block(){
        defend = true;
    }; 

    bool Monster::hasBlocked() {
        if (defend == true) {
            return true;
        } else
        return false;
    };

    void Monster::take_damage(int damage){; //taking damage from player
        if(defend == true){
        current_health = current_health - (0.75)*damage;
        std::cout << "\nYou did " << 0.75 * damage << " damage\n";
        std::cout << "The monster has " << current_health << " health left\n";   
        }
        else{
            current_health = current_health - damage;
            std::cout << "\nYou did " << damage << " damage\n";
            std::cout << "The monster has " << current_health << " health left\n";
        }
    }


    //getters and setters for data members
    int Monster::get_max_health(){
        return max_health;
    };

    int Monster::get_current_health(){
        return current_health;
    };

    int Monster::get_level(){
        return level;
    };

    void Monster::set_max_health(int health){
        max_health = health;
    };

    void Monster::set_current_health(int health){
        current_health = health;
    };

    void Monster::set_level(int level){
        level = level;
    };