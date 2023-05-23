#ifndef WAND_H
#define WAND_H
#include "Weapon.h"
#include <string>

class Wand : public Weapon {
    public:
        Wand();
        Wand(std::string name, int stat_bonus);
};
#endif