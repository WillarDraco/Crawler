#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"

class Barbarian : protected Player {
    private:
        int strength; // represents strength of a player - affects melee damage
        Weapon** barbarian_weapon; // currently equipped weapon
    public:
        Barbarian(); // sets all data members to 0 or “ ”
        Barbarian(int level); // sets strength and health based on level, exp = 0, current weapon = “”;

        void equipWeapon(Weapon* barbarian_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* barbarian_weapon); // sets current weapon to  “” (removes weapon bonuses)

        void swingWeapon(Monster* monster); // barbarian only attack that does damage based on strength and equipped weapon

        void rest(); // heals player for turn - based on total health
};
#endif