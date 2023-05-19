#include "Monster.h"
#include "Skeleton.h"
#include <cstdlib>

    //default constructer
    Skeleton::Skeleton(int level){
        agility = level;
        has_weapon = false;
    };

    //attack
    void Skeleton::attack(Player* player){
      int random_move = rand() % 100 + 1;
        
        if (random_move < 75){
            if (has_weapon = true){
                int damage = (rand() % 5 + 1) + (agility)*2;

                player->take_damage(damage);
            }
            else{
                int damage = (rand() % 5 + 1) + (agility);

                player->take_damage(damage);

            }
        }   
        else{
            block();    
        }    
    
    }

    void Skeleton::equipWeapon(){; // sets current weapon (weapon bonuses)
        has_weapon = true;
    }
    void Skeleton::unequipWeapon(){; // sets current weapon to  “” (removes weapon bonuses)
        has_weapon = false;
    }
    
    //getters and setters
    int Skeleton::get_agility(){
        return agility;
    };

    void Skeleton::set_agility(int agility){
        agility = agility;

    };