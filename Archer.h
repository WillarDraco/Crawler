#ifndef ARCHER_H
#define ARCHER_H
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"
#include <string>

class Archer : public Player {
    private:
        Weapon** archer_weapon; // currently equipped weapon
    public:
        Archer(); // sets all data members to 0 or “”
        Archer(int level, std::string name); // sets strength and health based on level, exp = 0, current weapon = “”;
        void gainExp(int exp); // Gain exp function to level up
        void equipWeapon(Weapon* archer_weapon); // sets current weapon (weapon bonuses)
        void unequipWeapon(Weapon* archer_weapon); // sets current weapon to  “” (removes weapon bonuses)
        
        void specialAttack(Monster* monster); // archer only attack that does damage based on agility and equipped weapon

        void rest(); // heals for turn - based on total health

        int get_agility(); // Gets agility value
        int get_max_ammo(); // Gets max ammo value
        int get_current_ammo(); // Gets current ammo value

        void set_agility(int agility); // Sets agility value
        void set_max_ammo(int max_ammo); // Gets max ammo value
        void set_current_ammo(int current_ammo); // Gets current ammo value
};
#endif