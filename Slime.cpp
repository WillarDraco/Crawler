#include "Monster.h"
#include "Slime.h"
#include <cstdlib>

    //default constructer
    Slime::Slime(int level){
        strength = level;
        mana = level * 2;
    };

    // basic attack
    void Slime::attack(Player* player){
           int random_move = rand() % 100 + 1;
        
        if (random_move < 75){
            if (random_move < 50){
                int damage = (rand() % 5 + 1) + (strength);

                player->take_damage(damage);
            }
            else if (random_move > 50){
                int damage = (rand() % 5 + 1) + (mana);

                player->take_damage(damage);

            }
        }   
        else{
            block();    
        }    
    
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