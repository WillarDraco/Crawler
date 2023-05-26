#include "Monster.h"
#include "Skeleton.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Skeleton::Skeleton(Player* player){
        this->level = player->get_level();
        this->defend = false;

        combat_stats[0] = 20 + 5*(level);
        combat_stats[1] = combat_stats[0];
        combat_stats[2] = 0;
        combat_stats[3] = 0;  
        combat_stats[4] = level;
        combat_stats[5] = 0;
        combat_stats[6] = level * 16;
         
        skeleton_weapon = 0;
    };

    //attack
    void Skeleton::attack(Player* player){
      int random_move = rand() % 100 + 1;
        defend = false;
        if (random_move < 75){
                combat_stats[2] = (rand() % 5 + 1) + (combat_stats[4]);

                player->takeDamage(combat_stats[2]);
        } 
        else{
            std::cout << "\nThe skeleton blocks!\n";
            block();    
        }    
    
    }

    void Skeleton::equipWeapon(Weapon* skeleton_weapon) { // sets current weapon (weapon bonuses)
        combat_stats[4] = combat_stats[4]+ skeleton_weapon->get_damage();
        this->skeleton_weapon = &skeleton_weapon;
    }

    void Skeleton::unequipWeapon(Weapon* skeleton_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        combat_stats[4] = combat_stats[4] - skeleton_weapon->get_damage();
        this->skeleton_weapon = 0;
    }
    
    //getters and setters
    int Skeleton::get_agility(){
        return combat_stats[4];
    };

    void Skeleton::set_agility(int agility){
        combat_stats[4] = agility;

    };