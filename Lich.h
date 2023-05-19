#ifndef LICH_H
#define LICH_H

#include "Boss.h"
#include "Player.h"

class Lich : public Boss{
    protected:
        int strength;
        int mana;

    public:
        Lich(int level); //constructer


        void punch(Player* player); // basic attack
        void magic_attack (Player* player); //magic attack
        

        //getters and setters
        int get_strength();
        int get_mana();
        
        void set_strength(int strength);
        void set_mana(int mana);


};

#endif