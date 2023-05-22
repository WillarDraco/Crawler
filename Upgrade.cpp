#include "Player.h"
#include "Barbarian.h"
#include "Archer.h"
#include "Wizard.h"
#include "Upgrade.h"

Upgrade::Upgrade(){}; //default constructer

void Upgrade::upgrade_strength(Barbarian* barbarian){

    int new_strength = barbarian->get_strength() + 2;

    barbarian->set_strength(new_strength);
};


void Upgrade::upgrade_agility(Archer* archer){; 

    int new_agility = archer->get_agility() + 2;
    
    archer->set_agility(new_agility);
};


void Upgrade::upgrade_mana(Wizard* wizard){

    int new_mana = wizard->get_max_mana() + 2;
    
    wizard->set_max_mana(new_mana);
};

void Upgrade::upgrade_weapon_bonus(Weapon* weapon){

    int new_weapon_bonus = weapon->get_stat_bonus() + 2;

    weapon->set_stat_bonus(new_weapon_bonus);
}