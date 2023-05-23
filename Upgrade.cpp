#include "Player.h"
#include "Barbarian.h"
#include "Archer.h"
#include "Wizard.h"
#include "Upgrade.h"

Upgrade::Upgrade(){}; //default constructer

void Upgrade::upgrade_class_stat(Player* player){
    combat_stats[4] = combat_stats[4] + 5*level;
};


void Upgrade::upgrade_dodge_chance(Player* player){
    combat_stats[5] = combat_stats[5] + 5*level;
};


void Upgrade::upgrade_defense (Player* player){
    combat_stats[6] = combat_stats[6] + 5*level;
};


void Upgrade::upgrade_crit_chance(Player* player){
    combat_stats[7] = combat_stats[7] + 5*level;
};


void Upgrade::upgrade_max_recourses(Player* player){
    combat_stats[8] = combat_stats[8] + 5*level;
};