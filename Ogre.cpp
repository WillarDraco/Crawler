#include "Boss.h"
#include "Ogre.h"

//default constructer to nothing
Ogre::Ogre(){}

//getters and setters
int Ogre::get_strength(){
    return strength;
};

int Ogre::get_agility(){
    return agility;
};
        
void Ogre::set_strength(int a){
    strength = a;
};
void Ogre::set_agility(int b){
    agility = b;
};