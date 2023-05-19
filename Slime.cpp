#include "Monster.h"
#include "Slime.h"
#include <cstdlib>

    //default constructer
    Slime::Slime(int level){
        strength = level;
        mana = level;
    };

    // basic attack
    void Slime::punch(Player* player){
        
        int damage = (rand() % 5 + 1) + (strength);

        player->take_damage(damage);
    }

    //magic attack
    void Slime::magic_attack(Player* player){
        
        int damage = (rand() % 5 + 1) + (mana);

        player->take_damage(damage);
    }

    
    //getters and setters
    int Slime::get_strength(){
        return strength;
    };

    void Slime::set_strength(int strength){
        strength = strength;

    };

      int Slime::get_mana(){
        return mana;
    };

    void Slime::set_mana(int mana){
        mana = mana;
    };