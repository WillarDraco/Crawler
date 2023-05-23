#include "Monster.h"
#include "Dragon.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Dragon::Dragon(Player* player){
        this->level = player->get_level();

        this->max_health = 90 + 10*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->strength = level * 2;
        this->mana = level * 3;
    };

    // basic attack
    void Dragon::attack(Player* player){
        
        int random_move = rand() % 100 + 1;
        defend = false;
        
        if (random_move < 75){
            if (random_move < 50){
                int damage = (rand() % 10 + 5) + (strength);

                player->take_damage(damage);
            }
            else if (random_move > 50){
                int damage = (rand() % 10 + 5) + (mana);

                player->take_damage(damage);

            }
        }   
        else{
            std::cout << "\nThe Dragon blocks!\n";
            block();    
        }    
    
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