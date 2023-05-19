#include "Monster.h"
#include "Dragon.h"
#include <cstdlib>

    //default constructer
    Dragon::Dragon(int level){
        strength = level * 2;
        mana = level * 2;
    };

    // basic attack
    void Dragon::punch(Player* player){
        
        int damage = (rand() % 10 + 5) + (strength);

        player->take_damage(damage);
    }

    //magic attack
    void Dragon::magic_attack(Player* player){
        
        int damage = (rand() % 10 + 5) + (mana);

        player->take_damage(damage);
    }

    
    //getters and setters
    int Dragon::get_strength(){
        return strength;
    };

    void Dragon::set_strength(int strength){
        strength = strength;

    };

      int Dragon::get_mana(){
        return mana;
    };

    void Dragon::set_mana(int mana){
        mana = mana;
    };