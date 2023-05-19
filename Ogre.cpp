#include "Boss.h"
#include "Ogre.h"
#include <cstdlib>

    //default constructer
    Ogre::Ogre(int level){
        strength = level * 2;
        agility = level * 2;

    }

    // basic attack
    void Ogre::punch(Player* player, int strength){
        
        int damage = (rand() % 10 + 5) + (strength);

        player->take_damage(damage);
    }

    // range attack
    void Ogre::punch(Player* player, int strength){
        
        int damage = (rand() % 10 + 5) + (agility);

        player->take_damage(damage);
    }

    void equipWeapon(Weapon){}; // sets current weapon (weapon bonuses)
    void unequipWeapon(Weapon){}; // sets current weapon to  “” (removes weapon bonuses)


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