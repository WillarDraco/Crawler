#include "Monster.h"
#include "Wyvern.h"
#include <cstdlib>

    //default constructer
    Wyvern::Wyvern(int level){
        mana = level;
    };

    //magic attack
    void Wyvern::magic_attack(Player* player){
        
        int damage = (rand() % 5 + 1) + (mana);

        player->take_damage(damage);
    }

    
    //getters and setters
    int Wyvern::get_mana(){
        return mana;
    };

    void Wyvern::set_mana(int mana){
        mana = mana;
    };