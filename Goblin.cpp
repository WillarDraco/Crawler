#include "Monster.h"
#include "Goblin.h"
#include <cstdlib>

    //default constructer
    Goblin::Goblin(int level){
        strength = level;
    };


    // basic attack
    void Goblin::punch(Player* player){
    
        int damage = (rand() % 5 + 1) + (strength);

        player->take_damage(damage);
    }


    void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
    void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

    
    //getters and setters
    int Goblin::get_strength(){
        return strength;
    };

    void Goblin::set_strength(int strength){
        strength = strength;

    };