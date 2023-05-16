#include "Wizard.h"

    Wizard::Wizard() { // sets all data members to 0 or “ ”
    }

    Wizard::Wizard(int level) { // sets mana and health based on level, exp = 0, current weapon = “”;
        max_health = (level * 10) + 90; // represents the max health of a player
        current_health = max_health; // current health of player
        exp = 0; // current number of experience points
        this->level = level; // total experience level
        defend = false; // sets defending state
        max_mana = (level * 10) + 90; // represents the maximum mana of a player - affects magic damage and usage
        current_mana = max_mana; // current mana level of player
    }

    void Wizard::equipWeapon(Weapon); // sets current weapon (weapon bonuses)
    void Wizard::unequipWeapon(Weapon); // sets current weapon to  “” (removes weapon bonuses)

    void Wizard::castSpell() { // wizard only attack that uses mana and does damage based on mana and equipped weapon
        int damage = max_mana * 10;
        
    }
    void Wizard::manaRegen(); // regenerates mana based on level each
    void Wizard::rest(); // heals player and recharges mana for turn - based on total health and mana