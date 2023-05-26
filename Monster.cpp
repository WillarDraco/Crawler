#include "Monster.h"
#include "Weapon.h"
#include "Player.h"
#include <cstdlib>
#include <iostream>
    
    //default constructer sets everything to basics
    Monster::Monster() {}; 

    //set health based on level
    Monster::Monster(Player* player){
        combat_stats[0] = 0; // Stats {max_hp (0), current_hp (1), damage(2), strength(3), agility()4, mana(5), exp(6)}
        combat_stats[1] = 0;
        combat_stats[2] = 0;
        combat_stats[3] = 0;
        combat_stats[4] = 0;
        combat_stats[5] = 0;
        combat_stats[6] = 0;

        level = player->get_level();
        defend = false;    
        };

    Monster::~Monster(){};

    // basic attack
    void Monster::attack(Player* player){}

    void Monster::equipWeapon(Weapon* weapon) {} // sets current weapon (weapon bonuses)
    void Monster::unequipWeapon(Weapon* weapon) {} // sets current weapon to  “” (removes weapon bonuses)
    

    // reduces taken damage for one turn
    void Monster::block(){
        defend = true;
    }; 

    //checks whether monster has or hasnt blocked
    bool Monster::hasBlocked() {
        if (defend == true) {
            return true;
        } else
        return false;
    };

    void Monster::takeDamage(int damage){; //taking damage from player
       if (defend == true) {
        std::cout << "\nThe monster blocked the players attack.\n";
        return;
    } else if (defend == false) {
        combat_stats[1] = combat_stats[1] - damage;
        std::cout << "\nThe player attacked for " << damage << " damage\n";
        std::cout << "The monster has " << combat_stats[1] << " health left\n";
        return;
    }
    }


    //getters and setters for data members
    int* Monster::get_combat_stats() {
    return combat_stats;
    }

    int Monster::get_max_health(){
        return combat_stats[0];
    };

    int Monster::get_current_health(){
        return combat_stats[1];
    };

    int Monster::get_level(){
        return level;
    };

    void Monster::set_max_health(int health){
        combat_stats[0] = health;
    };

    void Monster::set_current_health(int health){
        combat_stats[1] = health;
    };

    void Monster::set_level(int level){
        level = level;
    };