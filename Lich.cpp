#include "Monster.h"
#include "Lich.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Lich::Lich(Player* player){
        this->level = player->get_level();
        this->defend = false; 

        combat_stats[0] = 90 + 10*(level);
        combat_stats[1] = combat_stats[0];
        combat_stats[2] = 0;
        combat_stats[3] = level * 2;
        combat_stats[4] = 0;
        combat_stats[5] = level * 3;
        combat_stats[6] = level * 32;

        lich_weapon = 0;        

    };

    // basic attack
    void Lich::attack(Player* player){

        int random_move = rand() % 100 + 1;
        defend = false;

        if (random_move < 75){
            if(random_move < 50){
                combat_stats[2] = (rand() % 10 + 5) + (combat_stats[3]);

                player->takeDamage(combat_stats[2]);
            }
            else if (random_move > 50){
                combat_stats[2] = (rand() % 10 + 5) + (combat_stats[5]);

                player->takeDamage(combat_stats[2]); 
            }
        }   
        else{
            std::cout << "\nThe Lich blocks!\n";
            block();    
        }    
    
    }
     
    void Lich::equipWeapon(Weapon* lich_weapon) { // sets current weapon (weapon bonuses)
        combat_stats[5] = combat_stats[5] + lich_weapon->get_damage();
        this->lich_weapon = &lich_weapon;
    }

    void Lich::unequipWeapon(Weapon* lich_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        combat_stats[5] = combat_stats[5] - lich_weapon->get_damage();
        this->lich_weapon = 0;
    }

    //getters and setters
    int Lich::get_strength(){
        return combat_stats[3];
    };

    void Lich::set_strength(int strength){
        combat_stats[3] = strength;

    };

      int Lich::get_mana(){
        return combat_stats[5];
    };

    void Lich::set_mana(int mana){
        combat_stats[5] = mana;
    };