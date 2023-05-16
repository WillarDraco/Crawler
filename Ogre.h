#ifndef ORGE_H
#define ORGE_H

#include "Boss.h"

class Ogre : public Boss{
    protected:
        int strength;
        int agility;

    public:
        Ogre(); //default constructer

        //getters and setters
        int get_strength();
        int get_agility();
        
        void set_strength(int);
        void set_agility(int);


};

#endif