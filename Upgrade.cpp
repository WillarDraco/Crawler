#include "Player.h"
#include "Barbarian.h"
#include "Archer.h"
#include "Wizard.h"
#include "Upgrade.h"

Upgrade::Upgrade(){}; //default constructer

void Upgrade::upgrade_class_stat(Player* player){

    int new_stat = player->get_class_stat() + 5*level;
    player->set_class_stat(new_stat);
};


void Upgrade::upgrade_dodge_chance(Player* player){
     
    int new_stat = player->get_dodge_chance() + 5*level;
    player->set_dodge_chance(new_stat);
};


void Upgrade::upgrade_defense (Player* player){

    int new_stat = player->get_defense() + 5*level;
    player->set_defense(new_stat);
};


void Upgrade::upgrade_crit_chance(Player* player){
    
    int new_stat = player->get_crit_chance() + 5*level;
    player->set_crit_chance(new_stat);
};


void Upgrade::upgrade_max_recourses(Player* player){

    int new_stat = player->get_max_resource() + 5*level;
    player->set_max_resource(new_stat);
};