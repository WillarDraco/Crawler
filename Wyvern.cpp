#include "Monster.h"
#include "Wyvern.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Wyvern::Wyvern(Player* player){
        this->level = player->get_level();
        this->defend = false;

        combat_stats[0] = 20 + 5*(level);
        combat_stats[1] = combat_stats[0];
        combat_stats[2] = 0;
        combat_stats[3] = 0;
        combat_stats[5] = level;
        combat_stats[4] = 0;
        combat_stats[6] = level * 16;

    };

    //magic attack
    void Wyvern::magic_attack(Player* player){
             int random_move = rand() % 100 + 1;
             defend = false;
        
        if (random_move < 75){
            combat_stats[2] = (rand() % 5 + 1) + (combat_stats[5]);

                player->takeDamage(combat_stats[2]);
        }   
        else{
            std::cout << "\nThe Wyvern blocks!\n";
            block();    
        }    
    
    }

    
    //getters and setters
    int Wyvern::get_mana(){
        return combat_stats[5];
    };

    void Wyvern::set_mana(int mana){
        combat_stats[5] = mana;
    };