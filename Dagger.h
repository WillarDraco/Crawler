#ifndef DAGGER_H
#define DAGGER_H
#include "Weapon.h"
#include <string>
#include "Player.h"
#include "Monster.h"

class Dagger : protected Weapon {
    public:
        Dagger();
        Dagger(std::string name, int stat_bonus);
        // Dagger gives the player a 15% chance to evade all damage
        // Dagger gives the player a 15% chance to hit twice
};
#endif