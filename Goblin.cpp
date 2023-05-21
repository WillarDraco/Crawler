#include "Monster.h"
#include "Goblin.h"
#include <cstdlib>

    //constructer
    Goblin::Goblin(int level, Player* player){
        this->level = player->get_level();

        this->max_health = 20 + 5*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->strength = level;
        this->has_weapon = false;
    };


    //attack function
        void Goblin::attack(Player* player){
        int random_move = rand() % 100 + 1;
        
        if (random_move < 75){
            if (has_weapon == true){
                int damage = (rand() % 5 + 1) + (strength)*2;

                player->take_damage(damage);
            }
            else{
                int damage = (rand() % 5 + 1) + (strength);

                player->take_damage(damage);

            }
        }   
        else{
            block();    
        }
    }

    // sets weapon to true
    void Goblin::equipWeapon(){
        has_weapon = true;
    };

     // sets weapon to false
    void Goblin::unequipWeapon(){
        has_weapon = false;
    };

    

    //getters and setters
    int Goblin::get_strength(){
        return strength;
    };

    void Goblin::set_strength(int strength){
        strength = strength;

    };