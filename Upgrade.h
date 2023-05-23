#ifndef UPGRADE_H
#define UPGRADE_H

#include "Player.h"
#include "Barbarian.h"
#include "Archer.h"
#include "Wizard.h"
#include "Weapon.h"

class Upgrade: public Player {
    protected:
   
    public:
    Upgrade(); //default constructer
    
    void upgrade_class_stat (Player* player); //function for upgrading strength/agility/mana
    void upgrade_dodge_chance(Player* player); //upgrades the dodge chance stat
    void upgrade_defense (Player* player); //upgrades the defnense stat
    void upgrade_crit_chance(Player* player); //upgrades critical chance stat
    void upgrade_max_recourses(Player* player); //upgrades max recourses

    
};
#endif
