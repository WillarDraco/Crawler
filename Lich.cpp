#include "Monster.h"
#include "Lich.h"
#include <cstdlib>

    //default constructer
    Lich::Lich(int level){
        strength = level * 2;
        mana = level * 2;
    };

    // basic attack
    void Lich::punch(Player* player){
        
        int damage = (rand() % 10 + 5) + (strength);

        player->take_damage(damage);
    }

    //magic attack
    void Lich::magic_attack(Player* player){
        
        int damage = (rand() % 10 + 5) + (mana);

        player->take_damage(damage);
    }

    
    //getters and setters
    int Lich::get_strength(){
        return strength;
    };

    void Lich::set_strength(int strength){
        strength = strength;

    };

      int Lich::get_mana(){
        return mana;
    };

    void Lich::set_mana(int mana){
        mana = mana;
    };