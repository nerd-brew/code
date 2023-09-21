// Player.h

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

// Define Player class
class Player {
public:
    string name;
    int health;
    int baseAttack;
    int baseDefense;
    // Add more attributes as needed

    // Constructor
    Player(string n) {
        name = n;
        health = 100;
        baseAttack = 10;
        baseDefense = 5;
        // Initialize other attributes
    }

    // Method to display player stats
    void displayStats() {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Attack: " << baseAttack << endl;
        cout << "Defense: " << baseDefense << endl;
    }

    // Method to calculate damage for attack
    int attack() {
        int damage = baseAttack + (rand() % 5 + 1);
        return damage;
    }

    // Method to calculate defense
    int defend() {
        int damageTaken = baseDefense + (rand() % 5 + 1);
        return damageTaken;
    }

};

#endif