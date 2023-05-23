#include "Monster.h"
#include "Dragon.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Dragon::Dragon(Player* player){
        this->level = player->get_level();

        this->combat_stats[0] = 90 + 10*(level);
        this->combat_stats[1] = combat_stats[0];

        this->defend = false;    
        
        this->combat_stats[3] = level * 2;
        this->combat_stats[5] = level * 3;
        this->combat_stats[6] = level * 30;
    };

    // basic attack
    void Dragon::attack(Player* player){
        
        int random_move = rand() % 100 + 1;
        defend = false;
        
        if (random_move < 75){
            if (random_move < 50){
                combat_stats[2] = (rand() % 10 + 5) + (combat_stats[3]);

                player->take_damage(combat_stats[2]);
            }
            else if (random_move > 50){
                combat_stats[2] = (rand() % 10 + 5) + (combat_stats[5]);

                player->take_damage(combat_stats[2]);

            }
        }   
        else{
            std::cout << "\nThe Dragon blocks!\n";
            block();    
        }    
    
    }

    
    //getters and setters
    int Dragon::get_strength(){
        return combat_stats[3];
    };

    void Dragon::set_strength(int strength){
        combat_stats[3] = strength;

    };

      int Dragon::get_mana(){
        return combat_stats[5];
    };

    void Dragon::set_mana(int mana){
        combat_stats[5] = mana;
    };