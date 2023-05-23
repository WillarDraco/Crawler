#include "Dagger.h"
#include <string>

Dagger::Dagger() { // Default constructor

}

Dagger::Dagger(std::string name, int stat_bonus) { // Constructor for a dagger
    this->name = name;
    this->stat_bonus = stat_bonus;
}
