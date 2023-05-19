#ifndef ORGE_H
#define ORGE_H

#include "Boss.h"
#include "Player.h"

class Ogre : public Boss{
    protected:
        int strength;
        int agility;

    public:
        Ogre(int level); //constructer


        void punch(Player* player, int strength); // basic attack
        void range_attack (Player* player, int agility);

        void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)
        


        //getters and setters
        int get_strength();
        int get_agility();
        
        void set_strength(int);
        void set_agility(int);


};

#endif