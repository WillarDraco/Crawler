#include "Monster.h"
#include "Weapon.h"
#include "Player.h"
    
    //default constructer sets everything to nothing
    Monster::Monster(){}; 

    //set health based on level
    Monster::Monster(int level){
        max_health = 20 + 5*(level - 1);
        current_health = max_health;
    };

    // basic attack
    void Monster::punch(){
        int damage = 5 + 2*(level - 1);
    }; 

    // reduces taken damage for one turn
    void Monster::defend(){

    }; 

    void Monster::rest(){}; // heals for turn - based on total health

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