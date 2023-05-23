#include "Monster.h"
#include "Skeleton.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Skeleton::Skeleton(Player* player){
        this->level = player->get_level();

        this->max_health = 20 + 5*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->agility = level;
        
        skeleton_weapon = 0;
    };

    //attack
    void Skeleton::attack(Player* player){
      int random_move = rand() % 100 + 1;
        defend = false;
        if (random_move < 75){
                int damage = (rand() % 5 + 1) + (agility);

                player->take_damage(damage);
        } 
        else{
            std::cout << "\nThe skeleton blocks!\n";
            block();    
        }    
    
    }

    void Skeleton::equipWeapon(Weapon* skeleton_weapon) { // sets current weapon (weapon bonuses)
        agility = agility + skeleton_weapon->get_stat_bonus();
        this->skeleton_weapon = &skeleton_weapon;
    }

    void Skeleton::unequipWeapon(Weapon* skeleton_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        agility = agility - skeleton_weapon->get_stat_bonus();
        this->skeleton_weapon = 0;
    }
    
    //getters and setters
    int Skeleton::get_agility(){
        return agility;
    };

    void Skeleton::set_agility(int agility){
        agility = agility;

    };