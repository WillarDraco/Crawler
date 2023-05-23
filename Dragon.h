#ifndef DRAGON_H
#define DRAGON_H

#include "Boss.h"
#include "Player.h"

class Dragon : public Boss{
    protected:
       
    public:
        Dragon(Player* player); //constructer


        void attack(Player* player); // basic attack
        

        //getters and setters
        int get_strength();
        int get_mana();
        
        void set_strength(int strength);
        void set_mana(int mana);


};

#endif