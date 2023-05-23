#include "Monster.h"
#include "Goblin.h"
#include <cstdlib>
#include <iostream>

    //constructer
    Goblin::Goblin(Player* player){
        this->level = player->get_level();

        this->combat_stats[0] = 20 + 5*(level);
        this->combat_stats[1] = combat_stats[0];

        this->defend = false;    
        
        this->combat_stats[3] = level;

        goblin_weapon = 0;
    };


    //attack function
        void Goblin::attack(Player* player){
        int random_move = rand() % 100 + 1;
        defend = false;
        if (random_move < 75){
                combat_stats[2] = (rand() % 5 + 1) + (combat_stats[3]);
                player->take_damage(combat_stats[2]);

            }
          
        else{
            std::cout << "\nThe goblin blocks!\n";
            block();    
        }
    }

   void Goblin::equipWeapon(Weapon* goblin_weapon) { // sets current weapon (weapon bonuses)
        combat_stats[3] = combat_stats[3] + goblin_weapon->get_stat_bonus();
        this->goblin_weapon = &goblin_weapon;
}

    void Goblin::unequipWeapon(Weapon* goblin_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        combat_stats[3] = combat_stats[3] - goblin_weapon->get_stat_bonus();
        this->goblin_weapon = 0;
}
    

    //getters and setters
    int Goblin::get_strength(){
        return combat_stats[3];
    };

    void Goblin::set_strength(int strength){
        combat_stats[3] = strength;

    };