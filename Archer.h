#ifndef ARCHER_H
#define ARCHER_H
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"

class Archer : public Player {
    private:
        int agility; // represents the agility of a player - affects range damage
        Weapon** archer_weapon; // currently equipped weapon
        int max_ammo; // total arrows/bolts knives an archer can have
        int current_ammo; // current ammunition level
    public:
        Archer(); // sets all data members to 0 or “”
        Archer(int level); // sets strength and health based on level, exp = 0, current weapon = “”;

        void equipWeapon(Weapon* archer_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* archer_weapon); // sets current weapon to  “” (removes weapon bonuses)
        
        void shootWeapon(Monster* monster); // archer only attack that does damage based on agility and equipped weapon

        void recoverAmmo(); // recovers a random (small) amount of ammunition
        void rest(); // heals player for turn - based on total health
};
#endif