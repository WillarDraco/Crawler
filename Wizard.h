#ifndef WIZARD_H
#define WIZARD_H
#include "Player.h"
#include "Weapon.h"

class Wizard : protected Player {
    private:
        int max_mana; // represents the maximum mana of a player - affects magic damage and usage
        int current_mana; // current mana level of player
        Weapon** Wizard_Weapon; // currently equipped weapon

    public:
        Wizard(); // sets all data members to 0 or “ ”
        Wizard(int level); // sets mana and health based on level, exp = 0, current weapon = “”;

        void equipWeapon(Weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

        void castSpell(); // wizard only attack that uses mana and does damage based on mana and equipped weapon
        void manaRegen(); // regenerates mana based on level each
        void rest(); // heals player and recharges mana for turn - based on total health and mana
};
#endif