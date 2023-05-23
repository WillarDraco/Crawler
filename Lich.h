#ifndef LICH_H
#define LICH_H

#include "Boss.h"
#include "Player.h"

class Lich : public Boss{
    protected:
        Weapon** lich_weapon;

    public:
        Lich(Player* player); //constructer


        void attack(Player* player); // basic attack
        
        void equipWeapon(Weapon* lich_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* lich_weapon); // sets current weapon to  “” (removes weapon bonuses)


        //getters and setters
        int get_strength();
        int get_mana();
        
        void set_strength(int strength);
        void set_mana(int mana);


};

#endif