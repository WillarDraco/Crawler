#include "Monster.h"
#include "Skeleton.h"
#include <cstdlib>

    //default constructer
    Skeleton::Skeleton(int level){
        agility = level;
    };

    //range attack
    void Skeleton::range_attack(Player* player){
        
        int damage = (rand() % 5 + 1) + (agility);

        player->take_damage(damage);
    }

    void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
    void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

    
    //getters and setters
    int Skeleton::get_agility(){
        return agility;
    };

    void Skeleton::set_agility(int agility){
        agility = agility;

    };