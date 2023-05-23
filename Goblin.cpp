#include "Monster.h"
#include "Goblin.h"
#include <cstdlib>
#include <iostream>

    //constructer
    Goblin::Goblin(Player* player){
        this->level = player->get_level();

        this->max_health = 20 + 5*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->strength = level;

        goblin_weapon = 0;
    };


    //attack function
        void Goblin::attack(Player* player){
        int random_move = rand() % 100 + 1;
        defend = false;
        if (random_move < 75){
                int damage = (rand() % 5 + 1) + (strength);
                player->take_damage(damage);

            }
          
        else{
            std::cout << "\nThe goblin blocks!\n";
            block();    
        }
    }

   void Goblin::equipWeapon(Weapon* goblin_weapon) { // sets current weapon (weapon bonuses)
        strength = strength + goblin_weapon->get_stat_bonus();
        this->goblin_weapon = &goblin_weapon;
}

    void Goblin::unequipWeapon(Weapon* goblin_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        strength = strength - goblin_weapon->get_stat_bonus();
        this->goblin_weapon = 0;
}
    

    //getters and setters
    int Goblin::get_strength(){
        return strength;
    };

    void Goblin::set_strength(int strength){
        strength = strength;

    };