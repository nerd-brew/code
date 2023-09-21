#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables

// Character info
int playerHealth = 100;
int playerGold = 0;

// Function to simulate a battle
int battle() {
    printf("You encountered a monster!\n");
    return rand() % 2; // 0 means player loses, 1 means player wins
}

// Function to simulate an empty room
int emptyRoom() {
    if (rand() % 2 == 0) {
        printf("You found 10 gold!\n");
        playerGold += 10;
        return 1;
    }
    else {
        printf("You found nothing.\n");
        return 1;
    }
}

// Function to simulate a room
int room() {
    int result = 0;

    // 50% chance of a battle
    if (rand() % 2 == 0) {
        result = battle();
    }
    else {
        result = emptyRoom();;
    }

    return result;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    

    // Game state
    int currentRoom = 1;
    int choice = 0;

    printf("Welcome to Text RPG!\n");
    printf("You are in a dungeon.\n");
   

    while (playerHealth > 0) {

        printf("You have %d health and %d gold.\n", playerHealth, playerGold);
        printf("Will you go left or right?\n1. Left 2. Right\n");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("You went left.\n");
            if(room() == 0) {
                printf("You died.\n");
                break;
            }
            else {
                printf("You survived.\n");
            }
            currentRoom++;
        }
        else if (choice == 2) {
            printf("You went right.\n");
            if(room() == 0) {
                printf("You died.\n");
                break;
            }
            else {
                printf("You survived.\n");
            }
            currentRoom++;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}