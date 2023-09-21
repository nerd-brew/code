// Include necessary headers
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "player.h"
#include "enemy.h"
#include "item.h"

using namespace std;

// Global variables
int damage = 0;
int damageTaken = 0;

// Prototype functions
void displayMenu();

int main() {
    srand(time(0)); // Seed the random number generator

    cout << "Welcome to the RPG game!" << endl;

    /*
    *
    * Character creation
    * 
    */

    // Get player's name
    cout << "Enter your character's name: ";
    string playerName;
    cin >> playerName;

    // Create player object
    Player player(playerName);

    // Starting inventory
    vector<Item> inventory;
    int gold = 0;

    // Create health potion
    Item healthPotion("Health Potion", "healing", 20);
    inventory.push_back(healthPotion);


    // Display player stats
    player.displayStats();
    cout << endl;

    /*
    *
    * Main game loop 
    * 
    */

    // Combat loop
    while (player.health > 0) {
        // Generate a random enemy
        string enemyTypes[] = { "Goblin", "Orc", "Dragon", "Skeleton" };
        string randomEnemyType = enemyTypes[rand() % 4];
        Enemy enemy(randomEnemyType);
        cout << "You have encountered a " << enemy.type << "!" << endl;

        // Display enemy stats
        enemy.displayStats();

        // Loop until either player or enemy is dead
        while (player.health > 0 && enemy.health > 0){

            bool didPlayerEscape = false;

            displayMenu();

            // Get player's choice
            cout << "Enter your choice: " << endl;
            int choice;
            cin >> choice;
            cout << endl;

            // Handle player's choice
            switch (choice) {
                case 1:
                    // Player attacks enemy
                    damage = player.attack();
                    cout << "-> You dealt " << damage << " damage to the enemy!" << endl;
                    enemy.health = enemy.health - damage;

                    // Enemy attacks player
                    damageTaken = enemy.attack() - player.defend();
                    cout << "<- You took " << damageTaken << " damage!\n" << endl;
                    player.health = player.health - damageTaken;

                    break;
                case 2:
                    // Player defends
                    // Enemy attacks player
                    damageTaken = enemy.attack() - player.defend();
                    cout << "<- You took " << damageTaken / 4 << " damage!\n" << endl;
                    player.health = player.health - (damageTaken / 4); // Player takes 1/4 of the damage when defending

                    break;
                case 3:
                    // Player uses item, list items in a numbered list for player to select
                    cout << "Items are a WIP " << endl;


                    break;
                case 4:
                    // Player runs away, player has 50% chance of escaping
                    if (rand() % 2 == 0) {
                        cout << "-- You have successfully escaped! --" << endl;
                        didPlayerEscape = true;
                        break;
                    }
                    else {
                        cout << "-- You failed to escape! --" << endl;
                    }

                    // Enemy attacks player
                    damageTaken = enemy.attack() - player.defend();
                    cout << "You took " << damageTaken << " damage!\n" << endl;
                    player.health = player.health - damageTaken;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }

            // Check if enemy is dead or if player fled
            if (enemy.health <= 0) {
                cout << "You have defeated the " << enemy.type << "!" << endl;
                // Add gold to player's inventory
                gold += enemy.gold;
                cout << "You picked up " << enemy.gold << " gold!\n" << endl;
                break;
            }
            else if (didPlayerEscape) {
                break;
            }

            // Display player and enemy current health
            cout << "Player Health: " << player.health << " Enemy Health: " << enemy.health << endl;

        }

        // Check if player is dead
        if (player.health <= 0) {
            cout << "You have died!" << endl;
            break;
        }

        // Check if player wants to continue or quit
        cout << "Do you want to continue? (y/n): ";
        char continueChoice;
        cin >> continueChoice;

        if (continueChoice == 'n') {
            break;
        }

        // Repeat the loop
    }

    cout << "Game over! Your journey has ended." << endl;

    return 0;
}

// Function to display menu
void displayMenu() {
    cout << "|---------------------|" << endl;
    cout << "|-----1. Attack-------|" << endl;
    cout << "|-----2. Defend-------|" << endl;
    cout << "|-----3. Use item-----|" << endl;
    cout << "|-----4. Run away-----|" << endl;
    cout << "|---------------------|" << endl;
}

// Function that accept Item object as parameter


