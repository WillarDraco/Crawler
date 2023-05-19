#ifndef DRAGON_H
#define DRAGON_H

#include "Boss.h"
#include "Player.h"

class Dragon : public Boss{
    protected:
        int strength;
        int mana;

    public:
        Dragon(int level); //constructer


        void attack(Player* player); // basic attack
        

        //getters and setters
        int get_strength();
        int get_mana();
        
        void set_strength(int strength);
        void set_mana(int mana);


};

#endif