#ifndef BOW_H
#define BOW_H
#include "Weapon.h"
#include <string>

class Bow : protected Weapon {
    public:
        Bow();
        Bow(std::string name, int stat_bonus);
};
#endif