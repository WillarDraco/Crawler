#include "Monster.h"
#include "Slime.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Slime::Slime(Player* player){
        this->level = player->get_level();

        this->combat_stats[0] = 20 + 5*(level);
        this->combat_stats[1] = combat_stats[0];
        this->combat_stats[2] = 0;
        this->combat_stats[3] = level;
        this->combat_stats[4] = 0;        
        this->combat_stats[5] = level * 2;
        this->combat_stats[6] = level * 16;

        this->defend = false; 
    };

    // basic attack
    void Slime::attack(Player* player){
           int random_move = rand() % 100 + 1;
           defend = false;
        
        if (random_move < 75){
            if (random_move < 50){
                combat_stats[2] = (rand() % 5 + 1) + (combat_stats[3]);

                player->takeDamage(combat_stats[2]);
            }
            else if (random_move > 50){
                combat_stats[2] = (rand() % 5 + 1) + (combat_stats[5]);

                player->takeDamage(combat_stats[2]);

            }
        }   
        else{
            std::cout << "\nThe Slime blocks!\n";
            block();    
        }    
    
    }

    
    //getters and setters
    int Slime::get_strength(){
        return combat_stats[3];
    };

    void Slime::set_strength(int strength){
        combat_stats[3] = strength;

    };

      int Slime::get_mana(){
        return combat_stats[5];
    };

    void Slime::set_mana(int mana){
        combat_stats[5] = mana;
    };