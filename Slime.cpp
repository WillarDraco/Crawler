#include "Monster.h"
#include "Slime.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Slime::Slime(Player* player){
        this->level = player->get_level();

        this->max_health = 20 + 5*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->strength = level;
        this->mana = level * 2;
    };

    // basic attack
    void Slime::attack(Player* player){
           int random_move = rand() % 100 + 1;
           defend = false;
        
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
            std::cout << "\nThe Slime blocks!\n";
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