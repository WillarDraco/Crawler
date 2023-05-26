#include <iostream>
#include <string>
#include <limits>
#include <unistd.h>
#include <fstream>

#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Skeleton.h"
#include "Wyvern.h"

#include "Boss.h"
#include "Ogre.h"
#include "Dragon.h"
#include "Lich.h"

#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "Archer.h"

#include "Weapon.h"
#include "Wand.h"
#include "Dagger.h"
#include "Bow.h"
#include "Mace.h"
#include "BattleAxe.h"
#include "Crossbow.h"
#include "ThrowingKnives.h"
#include "Spellbook.h"
#include "Staff.h"
#include "Upgrade.h"



int main() {
    bool player_death = false;
    int classes_index;
    Player** classes = new Player*[3];

    std::cout << "Welcome to Crawler!" << "\n" << "Crawler is a turn-based "
        "rogue-like game where you take control of a player and defeat as many " 
        "monsters as you can,\nlevelling up and unlocking weapons along the way.\n";
    sleep(2);

    std::string new_or_continue;
    bool valid = false;
    
    while (valid == false) {
        std::cout << "Please enter 'New Game' to start a new game or 'Continue' to continue from save data\n";
        std::cin >> new_or_continue;
        if ((new_or_continue == "new") || (new_or_continue == "New")) {
            valid = true;
            delete classes;
        } else if ((new_or_continue == "continue") || (new_or_continue == "Continue")) {
            valid = true;
            std::ifstream savefile;
            savefile.open("savefile.txt");
                if (!savefile) {
                    std::cerr << "Error in opening the fil\nStart a new game\n";
                    valid = false;
                } else
                savefile.close();
        } else {
            std::cout << "Your selection is not valid, please try again";
        }
    }
    if ((new_or_continue == "Continue") || (new_or_continue == "continue")) {
        Player player;
        player.load();
        classes_index = 0;
        classes[classes_index] = &player;

    } else if ((new_or_continue == "New") || (new_or_continue == "new")) {
        
        // black screen, text pops up - character creation -
        std::string name;
        std::string _class;

        std::cout << "Enter a name: ";
        std::cin >> name;

        sleep(2);
        

        // create an array of pointers to pointers of each class type
        // player selects one to use and that pointer/index is used throughout the game

                
        Barbarian* barbarian = new Barbarian(1, name);
        Archer* archer = new Archer(1, name);
        Wizard* wizard = new Wizard(1, name);

        classes[0] = barbarian;
        classes[1] = archer;
        classes[2] = wizard;
        

        int classes_index;
        valid = false;
        while (valid == (false)) {
            std::cout << "Select a class, you may choose:\nBarbarian\nArcher\nWizard\n";
            std::cin >> _class;
    
            if (_class == ("Barbarian") || (_class == "barbarian")) {
                classes_index = 0;
                valid = true;
                _class = "Barbarian";
            } else if (_class == ("Archer") || _class == ("archer")) {
                classes_index = 1;
                valid = true;
                _class = "Archer";
            } else if (_class == ("Wizard") || _class == ("wizard")) {
                classes_index = 2;
                valid = true;
                _class = "Wizard";
            } else {
                std::cout << "Your selection is not valid, try again\n";
            }
        }

        sleep(2);

        std::cout << "You are " << name << " the " << _class << "\n" << "Press enter to continue\n";
        std::cin.get();
        std::cin.get();

        std::cout << "You open your eyes\n"; 
        sleep(2);
        std::cout << "The room is pitch black, your head hurts\n";
        sleep(2);
        std::cout << "You hear a growl, and you scramble to your feet as a goblin approaches...\n"; 
        sleep(2);

        Goblin tutorial_enemy = Goblin(classes[classes_index]); 
        // openGL fight scene appears

        // text boxes pop up explaining punch/defend/rest

        std::cout << "\nIn a fight, until you have a weapon you may Attack, Defend, Rest or perform a special action\n";
        sleep(2);
        std::cout << "Once an option is selected, the selected option occurs and it is now the enemys turn\n";
        sleep(2);
        std::cout << "Attack is a basic attack that does damage to the enemy. It won't do much until you get a weapon!\n";
        sleep(2);
        std::cout << "Defend reduces a small amount of damage taken on enemy's next turn\n";
        sleep(2);
        std::cout << "Rest recovers a small amount of health\n";
        sleep(2);
        std::cout << "Your special attack depends on your class type, for example, a Wizard can use fireball\n";
        sleep(2);

        // While loop until fight is over
        bool victory = false;
        bool player_death = false;
        while (victory == false && player_death == false) {
            // Loop to ensure valid selection
            bool valid = false;
            while (valid == false) {
                std::string selection;
                std::cout << "\nWill you attack, defend or rest?\n";
                std::cin >> selection;           
                if (selection == "Attack" || (selection == "attack")) {
                    tutorial_enemy.takeDamage(classes[classes_index]->get_combat_stats()[2]);
                    valid = true;
                } else if (selection == "Defend" || (selection == "defend")) {
                    classes[classes_index]->block();
                    valid = true;
                } else if (selection == "Rest" || (selection == "rest")) {
                    classes[classes_index]->rest();
                    valid = true;
                } else {
                    std::cout << "Your selection is not valid, try again\n";
                }            
            }
            if (tutorial_enemy.get_current_health() <= 0) {
                std::cout << "\nYou defeated the goblin!\n";
                victory = true;
                classes[classes_index]->increaseStandardKillCount();
                break;
            }

            tutorial_enemy.attack(classes[classes_index]);

            if (classes[classes_index]->get_current_health() <= 0) {
                std::cout << "\nYou died\n";
                player_death = true;
            }
        }

        classes[classes_index]->gainExp(10);


        // if player health reaches 0, trigger gameover and display playthrough statistics
        if (player_death == true) {
            std::string name = classes[classes_index]->get_name();
            std::cout << "Unfortunately " << name << " the " << _class << " has failed in their quest to reach the exit.\n";
            sleep(2);
            std::cout << name << " killed " << classes[classes_index]->get_standard_kill_count() << " monsters and " << classes[classes_index]->get_boss_kill_count() << " bosses.\n";
            sleep(2);
            std::cout << name << " reached level " << classes[classes_index]->get_level() << ".\n";
            sleep(2);
            std::cout << "While " << name << " may have failed in his quest, another may succeed...\n";
            sleep(2);
            std::cout << "Will you try again?\n";
            
            return 0;
        }

        // tutorial enemy drops weapon depending on class
        if (_class == "Barbarian") {
            std::cout << "\nYou notice a dirty blade tucked in the the goblins belt...\n";
            sleep(2);
            std::cout << "You take the blade from the body and see it's a goblins sword, rusty and dirty but sharp\n";
            sleep(2);
            std::cout << "The blade is too small to use as a sword but it could still do damage\nGratefully, you tuck the sword into your own belt, and as you begin to look around you\n";
            sleep(2);
            std::cout << "\nCongratulations! you have acquired a dagger!\n";
            sleep(2);
            std::cout << "\n Now that you have a dagger, you can use 'Special Attack' to swing your dagger\n";
            sleep(2);

        Dagger* first_dagger = new Dagger("Cracked Wand", classes[classes_index]->get_level());
        classes[classes_index]->equipWeapon(first_dagger);

        } else if (_class == "Archer") {
            std::cout << "\nYou notice a leather strap across the goblins chest, and upon closer insepction you realise\nthere is a quiver full of arrows across the goblins back...\n";
            sleep(2);
            std::cout << "The tips on the arrows look worn but still sharp enough to cut\n";
            sleep(2);
            std::cout << "Gratefully, you strap the quiver to your own back, and as you begin to look around you notice\nan old hunting bow in the corner of the room\n";
            sleep(2);
            std::cout << "\nCongratulations! You have acquired a Bow and Quiver!\n";
            sleep(2);
            std::cout << "\nNow that you have a Bow, you can use the 'Special Attack' in combat to shoot an arrow!\n";
            sleep(2);

        Bow* first_bow = new Bow("Cracked Wand", classes[classes_index]->get_level());
        classes[classes_index]->equipWeapon(first_bow);

        } else if (_class == "Wizard") {
            std::cout << "\nYou notice a strange old book in the goblins small satchel\n";
            sleep(2);
            std::cout << "You take the book and as you attempt to read it, you realise while most of it is in a language\nyou cannot understand\n";
            sleep(2);
            std::cout << "You look around the room and find it completely empty and decide to take a moment to glean\nwhat you can from this book\n";
            sleep(2);
            std::cout << "Several moments later you realise its a book about spellcraft! For now you can only understand\none spell but that is enough for now\n";
            sleep(2);
            std::cout << "You put the book back in the satchel and attach the satchel to your belt\n";
            sleep(2);
            std::cout << "\nCongratulation! You have acquired a spellbook!\n";
            sleep(2);
            std::cout << "\nNow that you have a spellbook, you can use the 'Special Attack' in combat to cast a fireball!\n";
            sleep(2);

        Spellbook* first_spellbook = new Spellbook("Cracked Wand", classes[classes_index]->get_level());
        classes[classes_index]->equipWeapon(first_spellbook);
    }

        std::cout << "Each weapon has unique bonuses, such as the chance to evade attacks, or double strike\n";
        sleep(2);
        std::cout << "You may find other weapons in your travels, but be warned, you can only carry one type at a time\n";
        sleep(2);
        std::cout << "\nStanding breathless over the dead body of the goblin, you look into the darkness\n";
        sleep(2);
        std::cout << "You decide the only way out is forwards, and with a grimace\n"
            "you take your first step into what seem to be an endless darkness...\n";
        sleep(2);
        std::cout << "\nPress Enter to continue...\n";
        std::cin.get();
        std::cin.get();  
    }
    

    // main gameplayer loop

        valid = false;
        std::string save;
        while (valid == false) {
            std::cout << "Would you like to save? Y/N\n";
            std::cin >> save;
            if (save == "Y") {
                valid = true;
                classes[classes_index]->save(classes[classes_index]);
            } else if (save == "N") {
                valid = true;
            } else {
                std::cout << "That selection was not valid, please try again";
            }
    
        }

        Monster** standard_monsters = new Monster*[3]; // fill arrays inside loop to account for changing player level
        Monster** boss_monsters = new Monster*[3];
        bool fight;
        int monster_select;
        int weapon_chance;
        int rand_weapon;
        player_death = false;
    while (player_death == false) {
        fight = true;
        
        if (classes[classes_index]->get_standard_kill_count() % 3 == 0) {  // after every 3rd normal enemy, fight boss
            Ogre* ogre = new Ogre(classes[classes_index]);
            Dragon* dragon = new Dragon(classes[classes_index]);
            Lich* lich = new Lich(classes[classes_index]);

            boss_monsters[0] = ogre;
            boss_monsters[1] = dragon;
            boss_monsters[2] = lich;

            monster_select = (rand() % 3);

            if (monster_select == 0) {
                std::cout << "\nAll of a sudden the ground starts shaking, and you can hear thuds in the distance, like the sound of thunder\n";
                sleep(2);
                std::cout << "Confused, you cautiously move forwards, and peer into the darkness\n";
                sleep(2);
                std::cout << "You come to a large room, and inside, is a giant creature that stinks of rot\n";
                sleep(2);
                std::cout << "You draw your weapon and prepare to fight the ogre\n";
                sleep(2);
            } else if (monster_select == 1) {
                std::cout << "\nYou pass through a giant empty room, with a ceiling so high you can't see the top\n";
                sleep(2);
                std::cout << "There appears to be nothing in it so your decide to rest your weary feet for a minute\n";
                sleep(2);
                std::cout << "Suddenly you hear the flap of giant wings, and a giant creature swoops down from the darkness";
                sleep(2);
                std::cout << "The creature circles you, breathing white hot flames that scorch the rock around you";
                sleep(2);
                std::cout << "You dive for cover, and prepare yourself to face the dragon\n";
                sleep(2);
            } else if (monster_select == 2) {
                std::cout << "\nAs you are walking you notice more and more bones appearing on the ground\n";
                sleep(2);
                std::cout << "Worryingly, most of them seem to be human remains\n";
                sleep(2);
                std::cout << "You hear a faint whispering, almost as if the ghost of these remains are whispering\n";
                sleep(2);
                std::cout << "The whispering gets louder and louder, and suddenly you sense something behind you";
                sleep(2);
                std::cout << "You whip around, and see one of the pile of bones start to float, and assemble upright into a full skeleton";
                sleep(2);
                std::cout << "Black robes seem to materialise around the skeleton, the bottom flaring as if there was some wind blowing it";
                sleep(2);
                std::cout << "With a cold sweat and fear in your heart, you prepare to fight the lich";
            }

            weapon_chance = rand() % 100;
            if (monster_select == 0 && (weapon_chance > 90)) {
            rand_weapon = rand() % 3;

                Dagger* dagger = new Dagger("Ogre's Sword", standard_monsters[monster_select]->get_level());
                Battleaxe* battleaxe = new Battleaxe("Ogre's Battleaxe", standard_monsters[monster_select]->get_level());
                Mace* mace = new Mace("Ogre's Mace", standard_monsters[monster_select]->get_level());
                Weapon** weaponlist = new Weapon*[3];

                weaponlist[0] = dagger;
                weaponlist[1] = mace;
                weaponlist[2] = battleaxe;

                boss_monsters[monster_select]->equipWeapon(weaponlist[rand_weapon]);
                
                switch (rand_weapon) {              
                case 0 :
                    std::cout << "The Ogre has a dagger!";
                    break;

                case 1 :
                    std::cout << "The Ogre has a mace!";
                    break;

                case 2 :
                    std::cout << "The Ogre has a battleaxe!";
                    break;

                default :
                    std::cout << "The Ogre has a weapon!";
                }

            } else if (monster_select == 2 && weapon_chance > 90) {
            rand_weapon = rand() % 3;

                Wand* wand= new Wand("Lich Wand", standard_monsters[monster_select]->get_level());
                Spellbook* spellbook = new Spellbook("Lich's Book of Spells", standard_monsters[monster_select]->get_level());
                Staff* staff = new Staff("Lich's Staff", standard_monsters[monster_select]->get_level());
                Weapon** weaponlist = new Weapon*[3];

                weaponlist[0] = wand;
                weaponlist[1] = spellbook;
                weaponlist[2] = staff;

                standard_monsters[monster_select]->equipWeapon(weaponlist[rand_weapon]);
                switch (rand_weapon) {              
                case 0 :
                    std::cout << "The Lich has a wand";
                    break;

                case 1 :
                    std::cout << "The Lich has a spellbook!";
                    break;

                case 2 :
                    std::cout << "The skeleton has a staff!";
                    break;

                default :
                    std::cout << "The skeleton has a weapon!";
                }
            }
            bool valid;
            while ((fight == true)) {
            
                valid = false;
                while (valid == false) {
                    std::string selection;
                    std::cout << "\nEnter: Attack, Defend, Rest or Special Attack\n";
                    std::cin >> selection;           
                    if (selection == "Attack" || (selection == "attack")) {
                        boss_monsters[monster_select]->takeDamage(classes[classes_index]->get_combat_stats()[2]);
                        valid = true;
                    } else if (selection == "Defend" || (selection == "defend")) {
                        classes[classes_index]->block();
                        valid = true;
                    } else if (selection == "Rest" || (selection == "rest")) {
                        classes[classes_index]->rest();
                        valid = true;
                    } else if (selection == "Special Attack" || selection == "special attack") {
                        boss_monsters[monster_select]->takeDamage(classes[classes_index]->get_combat_stats()[3]);
                    } else {
                        std::cout << "Your selection is not valid, try again\n";
                    } 
                }
                if (boss_monsters[monster_select]->get_current_health() <= 0) {
                    std::cout << "\nYou defeated the boss!\n";
                    classes[classes_index]->gainExp(boss_monsters[monster_select]->get_combat_stats()[6]);
                    fight = false;
                    classes[classes_index]->increaseBossKillCount();

                    //upgrades section
                    std::cout << "\nCongradulations, you have earned the choice of 3 upgrades. Enter 1, 2 or 3 to select your desired upgrade\n";
                    
                    int upgrade_one = rand() % 5;
                    switch (upgrade_one){
                        case 0:
                        std::cout << "\n1. Upgrade your class stat?\n";
                        break;

                        case 1:
                        std::cout << "\n1. Upgrade your dodge chance\n";
                        break;

                        case 2:
                        std::cout << "\n1. Upgrade your defense?\n";
                        break;

                        case 3:
                        std::cout << "\n1. Upgrade your critical chance?\n";
                        break;

                        case 4:
                        std::cout << "\n1. Upgrade your max recourses?\n";
                        break;
                    }


                    int upgrade_two = rand() % 5;

                    while ((upgrade_two == upgrade_one)){
                        upgrade_two = rand() % 5;
                    }

                    switch (upgrade_two){
                        case 0:
                        std::cout << "\n2. Upgrade your class stat?\n";
                        break;

                        case 1:
                        std::cout << "\n2. Upgrade your dodge chance\n";
                        break;

                        case 2:
                        std::cout << "\n2. Upgrade your defense?\n";
                        break;

                        case 3:
                        std::cout << "\n2. Upgrade your critical chance?\n";
                        break;

                        case 4:
                        std::cout << "\n2. Upgrade your max resourses?\n";
                        break;

                    }


                    int upgrade_three = rand() % 5;

                    while((upgrade_three == upgrade_one) || (upgrade_three == upgrade_one)){
                        upgrade_three = rand() % 5;
                    }

                    switch (upgrade_three){
                        case 0:
                        std::cout << "\n3. Upgrade your class stat?\n";
                        break;

                        case 1:
                        std::cout << "\n3. Upgrade your dodge chance\n";
                        break;

                        case 2:
                        std::cout << "\n3. Upgrade your defense?\n";
                        break;

                        case 3:
                        std::cout << "\n3. Upgrade your critical chance?\n";
                        break;

                        case 4:
                        std::cout << "\n3. Upgrade your max resourses?\n";
                        break;
                    }

                    Upgrade* upgrade = new Upgrade();
                    int requested_upgrade;
                    std::cin >> requested_upgrade;

                    while ((requested_upgrade =! 1 || 2 || 3)){
                        std::cout << "\nYour entry is invalid, please try again\n";
                        std::cin >> requested_upgrade;
                    }
                    
                    if((requested_upgrade == 1)){
                        switch (upgrade_one){

                        case 0:
                        upgrade->upgrade_class_stat(classes[classes_index]);
                        std::cout << "\nYou upgraded your class stat\n";
                        break;

                        case 1:
                        upgrade->upgrade_dodge_chance(classes[classes_index]);
                        std::cout << "\nYou upgraded your dodge chance\n";
                        break;

                        case 2:
                        upgrade->upgrade_defense(classes[classes_index]);
                        std::cout << "\nYou upgraded your defense\n";
                        break;

                        case 3:
                        upgrade->upgrade_crit_chance(classes[classes_index]);
                        std::cout << "\nYou upgraded your critical chance\n";
                        break;

                        case 4:
                        upgrade->upgrade_max_recourses(classes[classes_index]);
                        std::cout << "\nYou upgraded your max resourses\n";
                        break;       
                    };
                    } else if((requested_upgrade == 2)){
                        switch (upgrade_two){

                        case 0:
                        upgrade->upgrade_class_stat(classes[classes_index]);
                        std::cout << "\nYou upgraded your class stat\n";
                        break;

                        case 1:
                        upgrade->upgrade_dodge_chance(classes[classes_index]);
                        std::cout << "\nYou upgraded your dodge chance\n";
                        break;

                        case 2:
                        upgrade->upgrade_defense(classes[classes_index]);
                        std::cout << "\nYou upgraded your defense\n";
                        break;

                        case 3:
                        upgrade->upgrade_crit_chance(classes[classes_index]);
                        std::cout << "\nYou upgraded your critical chance\n";
                        break;

                        case 4:
                        upgrade->upgrade_max_recourses(classes[classes_index]);
                        std::cout << "\nYou upgraded your max resourses\n";
                        break;       
                    };
                    } else if((requested_upgrade == 3)){
                        switch (upgrade_one){

                        case 0:
                        upgrade->upgrade_class_stat(classes[classes_index]);
                        std::cout << "\nYou upgraded your class stat\n";
                        break;

                        case 1:
                        upgrade->upgrade_dodge_chance(classes[classes_index]);
                        std::cout << "\nYou upgraded your dodge chance\n";
                        break;

                        case 2:
                        upgrade->upgrade_defense(classes[classes_index]);
                        std::cout << "\nYou upgraded your defense\n";
                        break;

                        case 3:
                        upgrade->upgrade_crit_chance(classes[classes_index]);
                        std::cout << "\nYou upgraded your critical chance\n";
                        break;

                        case 4:
                        upgrade->upgrade_max_recourses(classes[classes_index]);
                        std::cout << "\nYou upgraded your max resourses\n";
                        break;       
                    };
                    };
                    break;
                }

                boss_monsters[monster_select]->attack(classes[classes_index]);

                if (classes[classes_index]->get_current_health() <= 0) {
                    std::cout << "\nYou died\n";
                    player_death = true;
                    fight = false;
                }
            }          
            delete ogre;
            delete lich;
            delete dragon;

        } else {
            Goblin* goblin = new Goblin(classes[classes_index]);
            Slime* slime = new Slime(classes[classes_index]);
            Skeleton* skeleton = new Skeleton(classes[classes_index]);
            Wyvern* wyvern = new Wyvern(classes[classes_index]);

            standard_monsters[0] = goblin;
            standard_monsters[1] = slime;
            standard_monsters[2] = skeleton;
            standard_monsters[3] = wyvern;

            monster_select = (rand() % 4);

            if (monster_select == 0) {
                std::cout << "\nAs you stumble through the darkness, you all of a sudden get the feeling that something is watching you\n";
                sleep(2);
                std::cout << "You spin around and are met with the dirty golden eyes of a goblin\n";
                sleep(2);
                std::cout << "You draw your weapon, ready to fight\n";
                sleep(2);
            } else if (monster_select == 1) {
                std::cout << "\nYou stumble over a rock, and to stop yourself falling you fling your arms out in front you\n";
                sleep(2);
                std::cout << "Instead of hard rock, your hands hit a gooey substance coating the ground\n";
                sleep(2);
                std::cout << "You look ahead at the slime, and prepare for combat";
                sleep(2);
            } else if (monster_select == 2) {
                std::cout << "\nAs you are walking, all of a sudden an arrow whizzes by your head\n";
                sleep(2);
                std::cout << "Ducking behind a nearby boulder, you hear the clinking of bones and arrows\n";
                sleep(2);
                std::cout << "You draw your weapon, jump out from behind the boulder, and charge at the skeleton archer\n";
            } else if (monster_select == 3) {
                std::cout << "\nAll of a sudden, you see light in the distance\n";
                sleep(2);
                std::cout << "Excitedly you start running toward it, but stop cold in your tracks when your eyes finally adjust to the light\n";
                sleep(2);
                std::cout << "The source of the light is fire, and that fire is coming from the mouth of a small wyvern\n";
                sleep(2);
                std::cout << "Squinting your eyes, you prepare to fight\n";
            }

            weapon_chance = rand() % 100;
            if (monster_select == 0 && (weapon_chance > 90)) {
                rand_weapon = rand() % 3;

                Dagger* dagger = new Dagger("Goblin's Sword", standard_monsters[monster_select]->get_level());
                Battleaxe* battleaxe = new Battleaxe("Goblin's Battleaxe", standard_monsters[monster_select]->get_level());
                Mace* mace = new Mace("Goblin's Mace", standard_monsters[monster_select]->get_level());
                Weapon** weaponlist = new Weapon*[3];

                weaponlist[0] = dagger;
                weaponlist[1] = mace;
                weaponlist[2] = battleaxe;

                standard_monsters[monster_select]->equipWeapon(weaponlist[rand_weapon]);
                
                switch (rand_weapon) {              
                case 0 :
                    std::cout << "The goblin has a dagger!";
                    break;

                case 1 :
                    std::cout << "The goblin has a mace!";
                    break;

                case 2 :
                    std::cout << "The goblin has a battleaxe!";
                    break;

                default :
                    std::cout << "The goblin has a weapon!";
                }

            } else if (monster_select == 2 && weapon_chance > 90) {
                rand_weapon = rand() % 3;

                Bow* bow = new Bow("Skeleton Bow", standard_monsters[monster_select]->get_level());
                Crossbow* crossbow = new Crossbow("Skeleton Crossbow", standard_monsters[monster_select]->get_level());
                ThrowingKnives* throwingknives = new ThrowingKnives("Skeleton Throwing Knives", standard_monsters[monster_select]->get_level());
                Weapon** weaponlist = new Weapon*[3];

                weaponlist[0] = bow;
                weaponlist[1] = crossbow;
                weaponlist[2] = throwingknives;

                standard_monsters[monster_select]->equipWeapon(weaponlist[rand_weapon]);
                switch (rand_weapon) {              
                case 0 :
                    std::cout << "The skeleton has a bow!";
                    break;

                case 1 :
                    std::cout << "The skeleton has a crossbow!";
                    break;

                case 2 :
                    std::cout << "The skeleton has throwing knives!";
                    break;

                default :
                    std::cout << "The skeleton has a weapon!";
                }
            }

            while ((fight == true)) {
            
                bool valid = false;
                while (valid == false) {
                    std::string selection;
                    std::cout << "\nEnter: Attack, Defend, Rest or Special Attack\n";
                    std::cin >> selection;           
                    if (selection == "Attack" || (selection == "attack")) {
                        standard_monsters[monster_select]->takeDamage(classes[classes_index]->get_combat_stats()[2]);
                        valid = true;
                    } else if (selection == "Defend" || (selection == "defend")) {
                        classes[classes_index]->block();
                        valid = true;
                    } else if (selection == "Rest" || (selection == "rest")) {
                        classes[classes_index]->rest();
                        valid = true;
                    } else if (selection == "Special Attack" || selection == "special attack") {
                        standard_monsters[monster_select]->takeDamage(classes[classes_index]->get_combat_stats()[3]);
                    } else {
                        std::cout << "Your selection is not valid, try again\n";
                    } 
                }
                if (standard_monsters[monster_select]->get_current_health() <= 0) {
                    std::cout << "\nYou defeated the monster!\n";
                    classes[classes_index]->gainExp(standard_monsters[monster_select]->get_combat_stats()[6]);
                    fight = false;
                    classes[classes_index]->increaseStandardKillCount();
                    break;
                }

                standard_monsters[monster_select]->attack(classes[classes_index]);

                if (classes[classes_index]->get_current_health() <= 0) {
                    std::cout << "\nYou died\n";
                    player_death = true;
                    fight = false;
                }
            }            
            delete goblin;
            delete slime;
            delete skeleton;
            delete wyvern;
        }
    } 
    }