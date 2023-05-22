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
    
    void upgrade_strength(Barbarian* barbarian); //function for upgrading strength
    void upgrade_agility(Archer* archer); //function for upgrading agility
    void upgrade_mana(Wizard* wizard); //function for upgrading mana

    void upgrade_weapon_bonus (Weapon* weapon); //function for upgrading the weapon bonus
    void switch_weapon(); //function for changing weapon

    


};
#endif
