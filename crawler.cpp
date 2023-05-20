#include <iostream>
#include <string>
#include <limits>
#include <unistd.h>
#include "Monster.h"
#include "Goblin.h"
#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "Archer.h"



int main() {

    std::cout << "Welcome to Crawler!" << "\n" << "Crawler is a turn-based "
        "rogue-like game where you take control of a player and defeat as many " 
        "monsters as you can, levelling up and unlocking weapons along the way.\n";

    sleep(2);

    // openGL start button and whatnot
    // black screen, text pops up - character creation -
    std::string name;
    std::string _class;

    std::cout << "Enter a name: ";
    std::cin >> name;

    sleep(0.5);

    Player** classes = new Player*[3];

    Barbarian* barbarian = new Barbarian(1);
    Archer* archer = new Archer(1);
    Wizard* wizard = new Wizard(1);

    classes[0] = barbarian;
    classes[1] = archer;
    classes[2] = wizard;

    int classes_index;
    bool valid_class = false;
    while (valid_class == false) {
        std::cout << "Select a class, you may choose:\nBarbarian\nArcher\nWizard\n";
        std::cin >> _class;
 
        if (_class == ("Barbarian") || _class == "barbarian") {
            classes_index = 0;
            valid_class = true;
            _class = "barbarian";
        } else if (_class == ("Archer") || _class == ("archer")) {
            classes_index = 1;
            valid_class = true;
            _class = "archer";
        } else if (_class == ("Wizard") || _class == ("wizard")) {
            classes_index = 2;
            valid_class = true;
            _class = "wizard";
        } else {
            std::cout << "Your selection is not valid, try again\n";
        }
    }
    if (_class == "wizard") {
        Wizard* user = new Wizard;
    } else if (_class == "archer") {
        Archer* user = new Archer;
    } else if (_class == "barbarian") {
        Barbarian* user = new Barbarian;
    } else


    sleep(0.5);

    std::cout << "You are a " << _class << " named " << name << "\n" << "Press enter to continue\n";
    std::cin.get();
    std::cin.get();

    std::cout << "You open your eyes\n"; 
    sleep(2);
    std::cout << "The room is pitch black, your head hurts\n";
    sleep(2);
    std::cout << "You hear a growl, and you scramble to your feet as a goblin approaches...\n"; 
    sleep(2);

    Goblin tutorial_enemy = Goblin(1); 
    // openGL fight scene appears

    // text boxes pop up explaining punch/defend/rest

    std::cout << "In a fight, until you have a weapon you may Punch, Defend or Rest\n";
    sleep(2);
    std::cout << "Once an option is selected, the selected option occurs and it is now the enemys turn\n";
    sleep(2);
    std::cout << "Attack is a basic attack that does damage to the enemy. It won't do much until you get a weapon!\n";
    sleep(2);
    std::cout << "Defend reduces a small amount of damage taken on enemy's next turn\n";
    sleep(2);
    std::cout << "Rest recovers a small amount of health\n";
    sleep(2);

    // While loop until fight is over
    bool victory = false;
    bool player_death = false;
    int enemy_move;
    int kill_count = 0;

    while (victory == false && player_death == false) {
        // Loop to ensure valid selection
        bool valid = false;
        while (valid == false) {
            std::string selection;
            std::cout << "Will you attack, defend or rest?\n";
            std::cin >> selection;           
            if (selection == ("attack","Attack")) {
                classes[classes_index]->attack(tutorial_enemy);
                valid = true;
            } else if (selection == ("Defend","defend")) {
                classes[classes_index]->block();
                valid = true;
            } else if (selection == ("Rest","rest")) {
                classes[classes_index]->rest();
                valid = true;
            } else {
                std::cout << "Your selection is not valid, try again\n";
            }            
        }
        if (tutorial_enemy.get_current_health() <= 0) {
            std::cout << "You defeated the goblin!";
            victory = true;
            kill_count++;
            break;
        }
        enemy_move = 1+ (rand() % 100);
        if (enemy_move < 75) {
            tutorial_enemy.attack(classes[classes_index]);
        } else {
            tutorial_enemy.block();
        }

        if (classes[classes_index]->get_current_health() <= 0) {
            std::cout << "You died";
            player_death = true;
        }
    }

    if (player_death == true) {
        //gameover, stats
        return 0;
    }

    sleep(2);
    std::cout << "Standing breathless over the dead body of the golbin, "
        "you look into the darkness";
    sleep(2);
    std::cout << "You decide the only way out is forwards, and with a grimace"
        " you take your first step into what seem to be an endless darkness...";
    sleep(2);
}

// tutorial enemy drops weapon

// if victory - check player levelup
// if player death

// main gameplayer loop

// KC % 3 == 0 run boss loop

// else run standard enemy loop

// combat - 2 enemy arrays, one boss one standard, generate rand enemy from array

// if victory - STDKC++/BKC++, check level, if Boss upgrades or heal

// if death - display kill count and boss kill count, display level
// game over