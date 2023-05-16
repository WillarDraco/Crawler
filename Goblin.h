#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"

class Goblin : public Monster{
    protected:
    int strength;

    public:
    Goblin(); //default constructor

    //getters and setters
    int get_strength();
    void set_strength(int);
};

#endif