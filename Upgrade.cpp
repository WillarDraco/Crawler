#include "Player.h"
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