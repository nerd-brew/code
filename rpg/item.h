// item.h

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "player.h"
#include "enemy.h"

using namespace std;

#ifndef ITEM_H
#define ITEM_H

// Define Item class
// Item class sets a name, attribute to be changed, and the value it's changed by
class Item {
public:
    string name;
    string typeOfEffect;
    int value;

    // Constructor
    Item(string n, string a, int v) {
        name = n;
        typeOfEffect = a;
        value = v;
    }

    // Method to display item stats
    void displayStats() {
        cout << "Name: " << name << endl;
        cout << "Effect: " << typeOfEffect << endl;
        cout << "Value: " << value << endl;
    }
};

#endif

