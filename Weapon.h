#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
    protected:
        int damage; // I
    private:
        virtual void stat_increase();
        virtual void damage_increase();
};

#endif