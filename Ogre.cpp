#include "Boss.h"
#include "Ogre.h"
#include <cstdlib>
#include <iostream>

    //constructer
    Ogre::Ogre(Player* player){
        this->level = player->get_level();

        this->max_health = 90 + 10*(level);
        this->current_health = max_health;

        this->defend = false;    
        
        this->strength = level * 2;
        this->agility = level * 3;
        ogre_weapon = 0;

    }

    // basic attack
    void Ogre::attack(Player* player){

        int random_move = rand() % 100 + 1;
        defend = false;

        if (random_move < 75){
            if(random_move < 50){
                int damage = (rand() % 10 + 5) + (strength);

                player->take_damage(damage);
            }
            else if (random_move > 50){
                int damage = (rand() % 10 + 5) + (agility);

                player->take_damage(damage); 
            }
        }   
        else{
            std::cout << "\nThe Ogre blocks!\n";
            block();    
        }    
    
    }
    


    void Ogre::equipWeapon(Weapon* ogre_weapon) { // sets current weapon (weapon bonuses)
        strength = strength + ogre_weapon->get_stat_bonus();
        this->ogre_weapon = &ogre_weapon;
    }

    void Ogre::unequipWeapon(Weapon* ogre_weapon) { // sets current weapon to  “” (removes weapon bonuses)
        strength = strength - ogre_weapon->get_stat_bonus();
        this->ogre_weapon = 0;
    }


    //getters and setters
    int Ogre::get_strength(){
        return strength;
    };

    int Ogre::get_agility(){
        return agility;
    };
            
    void Ogre::set_strength(int strength){
        strength = strength;
    };
    void Ogre::set_agility(int agility){
        agility = agility;
    };