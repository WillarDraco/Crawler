#ifndef ORGE_H
#define ORGE_H

#include "Boss.h"
#include "Player.h"

class Ogre : public Boss{
    protected:
        int strength;
        int agility;
        Weapon** ogre_weapon;

    public:
        Ogre(Player* player); //constructer


        void attack(Player* player); // basic attack

        void equipWeapon(Weapon* ogre_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* ogre_weapon); // sets current weapon to  “” (removes weapon bonuses)
        


        //getters and setters
        int get_strength();
        int get_agility();
        
        void set_strength(int);
        void set_agility(int);


};

#endif