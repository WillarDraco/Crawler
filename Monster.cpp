#include "Monster.h"
#include "Weapon.h"
#include "Player.h"
#include <cstdlib>
    
    //default constructer sets everything to nothing
    Monster::Monster(){}; 

    //set health based on level
    Monster::Monster(int level){
        max_health = 20 + 5*(level - 1);
        current_health = max_health;
    };

    // basic attack
    void Monster::attack(Player* player){}

    // reduces taken damage for one turn
    bool Monster::block(){
        defend = true;
    }; 

    void Monster::take_damage(int damage){; //taking damage from player
        if (defend = true){
            current_health = current_health - damage*(0.5);
        }
        else{
            current_health = current_health - damage;
        }
    }

    void Monster::equipWeapon(Weapon){}; // sets current weapon (weapon bonuses)
    void Monster::unequipWeapon(Weapon){}; // sets current weapon to  “” (removes weapon bonuses)
        

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

    void Monster::set_max_health(int a){
        max_health = a;
    };

    void Monster::set_current_health(int b){
        current_health = b;
    };

    void Monster::set_level(int c){
        level = c;
    };