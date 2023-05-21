#ifndef LICH_H
#define LICH_H

#include "Boss.h"
#include "Player.h"

class Lich : public Boss{
    protected:
        int strength;
        int mana;
        bool has_weapon;

    public:
        Lich(Player* player); //constructer


        void attack(Player* player); // basic attack
        
        void equipWeapon(); // sets current weapon (weapon bonuses)
        void unequipWeapon(); // sets current weapon to  “” (removes weapon bonuses)


        //getters and setters
        int get_strength();
        int get_mana();
        
        void set_strength(int strength);
        void set_mana(int mana);


};

#endif