#include <iostream>
#include <string>



int main() {

    std::cout << "Welcome to Crawler!" << "\n" << "Crawler is a turn-based "
        "rogue-like game where you take control of a player and defeat as many " 
        "monsters as you can, levelling up and unlocking weapons along the way.\n";

    // openGL start button and whatnot
    // black screen, text pops up - character creation -
    std::string name;
    std::string _class;

    std::cout << "Enter a name: ";
    std::cin >> name;

    bool valid_class = false;
    while (valid_class == false) {
    std::cout << "Select a class, you may choose:\nBarbarian\nArcher\nWizard\n";
    std::cin >> _class;

    if (_class == ("Barbarian", "barbarian")) {

        valid_class = true;
    } else if (_class == ("Archer", "archer")) {

        valid_class = true;
    } else if (_class == ("Wizard", "wizard")) {

        valid_class = true;
    } else
        std::cout << "Your selection is not valid, try again\n";
    }

    std::cout << "You are an" << _class << "named" << name << "\n" << "Press enter to continue";
    std::cin >> 
    std::cout << "You open your eyes\n" << "The room is pitch black\n" << "You hear" 
        " a squelch, and you scramble to your feet as the slime approaches...\n"; 

        
    // openGL fight scene appears

    // text boxes pop up explaining punch/defend/rest

    std::cout << "In a fight, until you have a weapon you may Punch, Defend or Rest\n"
        "Once an option is selected, the selected option occurs and it is now the enemys turn\n"
        "Punch is a basic attack that does a small amount of damage to the enemy\n"
        "Defend reduces a small amount of damage taken on enemy's next turn\n"
        "Rest reduces a small amount of health\n";

    //Loop to ensure valid selection
    bool valid = false;
    while (valid == false) {
        std::string selection;
        std::cout << "Will you punch, defend or rest?\n";
        std::cin >> selection;

        if (selection == ("Punch","punch")) {
        
        valid = true;
        } else if (selection == ("Defend","defend")) {
        
        valid = true;
        } else if (selection == ("Rest","rest")) {
        
        valid = true;
        } else
            std::cout << "Your selection is not valid, try again\n";
    }

}