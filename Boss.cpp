#include "Monster.h"
#include "Boss.h"

//default constructer setting to nothing
Boss::Boss(){}; 

//constructer setting health
Boss::Boss(int level){
    max_health = 100 + 10*(level-1);
    current_health = max_health;
}
