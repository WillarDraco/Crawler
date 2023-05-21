#include "Monster.h"
#include "Weapon.h"
#include "Player.h"
#include <cstdlib>
    
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
        if (defend == true){
            current_health = current_health - damage*(0.5);
        }
        else{
            current_health = current_health - damage;
        }
    }

    //void Monster::equipWeapon(Weapon){}; // sets current weapon (weapon bonuses)
    //void Monster::unequipWeapon(Weapon){}; // sets current weapon to  “” (removes weapon bonuses)
        

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