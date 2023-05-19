#include "Boss.h"
#include "Ogre.h"
#include <cstdlib>

    //default constructer
    Ogre::Ogre(int level){
        strength = level * 2;
        agility = level * 2;

    }

    // basic attack
    void Ogre::attack(Player* player){

        int random_move = rand() % 100 + 1;
        
        if (random_move < 75){
            if (has_weapon = true){
                if (random_move < 50){
                int damage = (rand() % 10 + 5) + (strength * 2);

                player->take_damage(damage);
                }
                else if (random_move > 50){
                int damage = (rand() % 10 + 5) + (agility);

                player->take_damage(damage);
                }
            else if(random_move < 50){
                int damage = (rand() % 10 + 5) + (strength);

                player->take_damage(damage);
            }
            else if (random_move > 50){
                int damage = (rand() % 10 + 5) + (agility);

                player->take_damage(damage); 
            }
        }   
        else{
            block();    
        }    
    
    }
    }


    // sets current weapon (weapon bonuses)
    void Ogre::equipWeapon(){
        has_weapon = true;
    };

    // sets current weapon to  “” (removes weapon bonuses)
    void Ogre::unequipWeapon(){
        has_weapon = false;
    }; 


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