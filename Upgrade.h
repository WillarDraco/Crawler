#ifndef UPGRADE_H
#define UPGRADE_H

#include "Player.h"
#include "Barbarian.h"
#include "Archer.h"
#include "Wizard.h"

class Upgrade{
    protected:

    public:

    void upgrade_strength(Barbarian* barbarian);
    void upgrade_agility(Archer* archer);
    void upgrade_mana(Wizard* wizard);

    


};
#endif
