// Enemy.h

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

// Define Enemy class
class Enemy {
public:
    string type;
    int health;
    int baseAttack;
    int gold;
    // Add more attributes as needed

    // Constructor
    Enemy(string t) {
        type = t;
        health = rand() % 50 + 50; // Random health between 50 and 100
        baseAttack = rand() % 10 + 5;  // Random attack between 5 and 15
        gold = rand() % 10 + 1; // Random gold between 1 and 10
        // Initialize other attributes
    }

    // Method to display enemy stats
    void displayStats() {
        cout << "Enemy Health: " << health << endl;
        cout << "Enemy Attack: " << baseAttack << endl;
    }

    // Method to calculate damage for attack
    int attack() {
        int damage = baseAttack + (rand() % 5 + 1);
        return damage;
    }

};

#endif