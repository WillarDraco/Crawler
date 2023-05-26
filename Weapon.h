#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <vector>

class Weapon {
    protected:
        std::string name; // represents name of player’s weapon
        int weapon_stats[10]; // Vector to hold combat stats
        int level; // represents the level of the weapon
    public:
        Weapon(); // default constructor sets name to “” and stat bonus to 0
        Weapon(std::string name, int level); // constructor setting level, name and stat bonus
        
       // getters and setters for all data memebers
        int* get_weapon_stats();
        int get_max_health();
        int get_current_health();
        int get_level();
        std::string get_name();
        int get_damage();
        int get_special_damage();
        int get_resource_stat();
        int get_dodge_chance();
        int get_defense();
        int get_crit_chance();
        int get_current_resource();
        int get_max_resource();

        void set_max_health(int health);
        void set_current_health(int health);
        void set_level(int level);
        void set_name(std::string name);
        void set_damage(int damage);
        void set_special_damage(int special);
        void set_resource_stat(int resource);
        void set_dodge_chance(int dodge);
        void set_defense(int defense);
        void set_crit_chance(int crit);
        void set_current_resource(int resource);
        void set_max_resource(int resource);
};
#endif