#include "Boss.h"
#include "Ogre.h"
#include <cstdlib>
#include <iostream>

    //constructer
    Ogre::Ogre(Player* player){
        this->level = player->get_level();

        this->combat_stats[0] = 90 + 10*(level);
        this->combat_stats[1] = combat_stats[0];

        this->defend = false;    
        
        this->combat_stats[3] = level * 2;
        this->combat_stats[4] = level * 3;
        this->combat_stats[6] = level * 32;

        ogre_weapon = 0;

    }

    // basic attack
    void Ogre::attack(Player* player){

        int random_move = rand() % 100 + 1;
        defend = false;

        if (random_move < 75){
            if(random_move < 50){
                combat_stats[2] = (rand() % 10 + 5) + (combat_stats[3]);

                player->takeDamage(combat_stats[2]);
            }
            else if (random_move > 50){
                combat_stats[2] = (rand() % 10 + 5) + (combat_stats[4]);

                player->takeDamage(combat_stats[2]); 
            }
        }   
        else{
            std::cout << "\nThe Ogre blocks!\n";
            block();    
        }    
    
    }
    


    void Ogre::equipWeapon(Weapon* ogre_weapon) { // sets current weapon (weapon bonuses)
        combat_stats[3] = combat_stats[3] + ogre_weapon->get_stat_bonus();
        this->ogre_weapon = &ogre_weapon;
    }

    void Ogre::unequipWeapon(Weapon* ogre_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        combat_stats[3] = combat_stats[3] - ogre_weapon->get_stat_bonus();
        this->ogre_weapon = 0;
    }


    //getters and setters
    int Ogre::get_strength(){
        return combat_stats[3];
    };

    int Ogre::get_agility(){
        return combat_stats[4];
    };
            
    void Ogre::set_strength(int strength){
        combat_stats[3] = strength;
    };
    void Ogre::set_agility(int agility){
        combat_stats[4] = agility;
    };