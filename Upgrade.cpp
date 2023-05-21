#include "Player.h"
#include "Barbarian.h"
#include "Archer.h"
#include "Wizard.h"
#include "Upgrade.h"

void Upgrade::upgrade_strength(Barbarian* barbarian){

    int new_strength = barbarian->get_strength() + 2;

    barbarian->set_strength(new_strength);
};

void upgrade_agility(Archer* archer){; 

    int new_agility = archer->get_agility() + 2;
    
    archer->set_agility(new_agility);
};

void upgrade_mana(Wizard* wizard){

    int new_mana = wizard->get_max_mana() + 2;
    
    wizard->set_max_mana(new_mana);
};#include "Player.h"
#include "Upgrade.h"

//constructer
Upgrade::Upgrade(){
    this->  upgrade_strength = false;
    this->  upgrade_agility = false;
    this->  upgrade_mana = false;
}


//functions for setting upgrades to true
void Upgrade::choose_strength(){
    upgrade_strength = true;
}

void Upgrade::choose_agility(){
    upgrade_agility = true;
}

void Upgrade::choose_mana(){
    upgrade_mana = true;
}