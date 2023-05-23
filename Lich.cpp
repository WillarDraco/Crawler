#include "Monster.h"
#include "Lich.h"
#include <cstdlib>
#include <iostream>

    //default constructer
    Lich::Lich(Player* player){
        this->level = player->get_level();

        this->max_health = 90 + 10*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->strength = level * 2;
        this->mana = level * 2;

        lich_weapon = 0;        

    };

    // basic attack
    void Lich::attack(Player* player){

        int random_move = rand() % 100 + 1;
        defend = false;

        if (random_move < 75){
            if(random_move < 50){
                int damage = (rand() % 10 + 5) + (strength);

                player->take_damage(damage);
            }
            else if (random_move > 50){
                int damage = (rand() % 10 + 5) + (mana);

                player->take_damage(damage); 
            }
        }   
        else{
            std::cout << "\nThe Lich blocks!\n";
            block();    
        }    
    
    }
     
    void Lich::equipWeapon(Weapon* lich_weapon) { // sets current weapon (weapon bonuses)
        mana = mana + lich_weapon->get_stat_bonus();
        this->lich_weapon = &lich_weapon;
    }

    void Lich::unequipWeapon(Weapon* lich_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        mana = mana - lich_weapon->get_stat_bonus();
        this->lich_weapon = 0;
    }

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