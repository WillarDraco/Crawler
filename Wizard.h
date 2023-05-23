#ifndef WIZARD_H
#define WIZARD_H
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"
#include <string>

class Wizard : public Player {
    private:
        Weapon** wizard_weapon; // currently equipped weapon
    public:
        Wizard(); // sets all data members to 0 or “ ”
        Wizard(int level, std::string name); // sets mana and health based on level, exp = 0, current weapon = “”, name is inherited;
        void Wizard::gainExp(int exp); // Gain exp function after defeating a monster

        void equipWeapon(Weapon* wizard_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* wizard_weapon); // sets current weapon to  “” (removes weapon bonuses)

        void specialAttack(Monster* monster); // wizard only attack that uses mana and does damage based on mana and equipped weapon
        void rest(); // heals player and recharges mana for turn - based on total health and mana

        int get_max_mana(); // Gets max mana
        int get_current_mana(); // Gets current mana
        void set_max_mana(int mana); // Sets max mana
        void set_current_mana(int mana); // Sets current mana
};
#endif