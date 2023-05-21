#include "Monster.h"
#include "Lich.h"
#include <cstdlib>

    //default constructer
    Lich::Lich(Player* player){
        this->level = player->get_level();

        this->max_health = 90 + 10*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->strength = level * 2;
        this->mana = level * 2;
        this->has_weapon = false;        

    };

    // basic attack
    void Lich::attack(Player* player){

        int random_move = rand() % 100 + 1;
        
        if (random_move < 75){
            if (has_weapon = true){
                if (random_move < 50){
                int damage = (rand() % 10 + 5) + (strength);

                player->take_damage(damage);
                }
                else if (random_move > 50){
                int damage = (rand() % 10 + 5) + (mana * 2);

                player->take_damage(damage);
                }
            else if(random_move < 50){
                int damage = (rand() % 10 + 5) + (strength);

                player->take_damage(damage);
            }
            else if (random_move > 50){
                int damage = (rand() % 10 + 5) + (mana);

                player->take_damage(damage); 
            }
        }   
        else{
            block();    
        }    
    
    }
    }  

    // sets current weapon (weapon bonuses)
    void Lich::equipWeapon(){
        has_weapon = true;
    };

    // sets current weapon to  “” (removes weapon bonuses)
    void Lich::unequipWeapon(){
        has_weapon = false;
    };
    

    //getters and setters
    int Lich::get_strength(){
        return strength;
    };

    void Lich::set_strength(int strength){
        strength = strength;

    };

      int Lich::get_mana(){
        return mana;
    };

    void Lich::set_mana(int mana){
        mana = mana;
    };