#include "Monster.h"
#include "Goblin.h"

    //default constructer
    Goblin::Goblin(){};

    
    //getters and setters
    int Goblin::get_strength(){
        return strength;
    };

    void Goblin::set_strength(int a){
        strength = a;

    };