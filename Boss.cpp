#include "Monster.h"
#include "Boss.h"

//default constructer setting to nothing
Boss::Boss(){}; 

//constructer setting health and exp
Boss::Boss(Player* player){
    combat_stats = {0, 0, 0, 0, 0, 0, 0}; // Stats {max_hp (0), current_hp (1), damage(2), strength(3), agility()4, mana(5), exp(6)}
        
    level = player->get_level();

    combat_stats[0] = 90 + 10*(level);
    combat_stats[1] = combat_stats[0];
    combat_stats[6] = level * 32;

    defend = false; 
}
