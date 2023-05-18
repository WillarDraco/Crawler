#include "Wizard.h"
#include "Monster.h"

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

    void Wizard::castSpell(Monster* monster) { // wizard only attack that uses mana and does damage based on mana and equipped weapon
        int damage = max_mana * 10;
        if (monster->block() == true) {
            damage = damage * 0.85;
            monster->take_damage(damage);
        } else {
            monster->take_damage(damage);
        }
    }

    void Wizard::manaRegen() { // regenerates mana based on level each
        current_mana = current_mana + max_mana * 0.5;
        if (current_mana > max_mana) {
            current_mana = max_mana;
        }
    }

    void Wizard::rest() { // heals player and recharges mana for turn - based on total health and mana
        current_health = current_health + max_health * 0.25;
    }