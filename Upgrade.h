#ifndef UPGRADE_H
#define UPGRADE_H

#include "Player.h"
#include "Barbarian.h"
#include "Archer.h"
#include "Wizard.h"
#include "Weapon.h"

class Upgrade{
    protected:
   
    public:
    Upgrade(); //default constructer
    
    void upgrade_strength(Barbarian* barbarian); 
    void upgrade_agility(Archer* archer); 
    void upgrade_mana(Wizard* wizard);

    void upgrade_weapon_bonus (Weapon* weapon);
    void change_weapon();

    


};
#endif
