#include "Monster.h"
#include "Wyvern.h"
#include <cstdlib>

    //default constructer
    Wyvern::Wyvern(Player* player){
        this->level = player->get_level();

        this->max_health = 20 + 5*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->mana = level;
    };

    //magic attack
    void Wyvern::magic_attack(Player* player){
             int random_move = rand() % 100 + 1;
        
        if (random_move < 75){
            int damage = (rand() % 5 + 1) + (mana);

                player->take_damage(damage);
        }   
        else{
            block();    
        }    
    
    }

    
    //getters and setters
    int Wyvern::get_mana(){
        return mana;
    };

    void Wyvern::set_mana(int mana){
        mana = mana;
    };