//************************************************************************
//Author.....: Devan Marion
//Assignment: Escape the Dungeon
//Despcription: This program provides a simple dungeon adventure game 
//************************************************************************ 

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Clears invalid input from the input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper function to check if an item exists in the inventory
bool hasItem(const vector<string>& inventory, const string& item) {
    for (const string& i : inventory) {
        if (i == item) return true;
    }
    return false;
}

int main() {
    int health = 100; // Player starts with full health
    vector<string> inventory; // Inventory to hold player items

    // Game Introduction
    cout << "============================\n";
    cout << "   Welcome to 'Escape the Dungeon'\n";
    cout << "============================\n";
    cout << "You wake up in a cold, damp dungeon with nothing but your instincts.\n";
    cout << "Mission: Escape... if you can.\n";
    cout << "You have " << health << " health.\n\n";

      // Starting items
      cout << "You find a rusty sword and a small healing potion near you.\n";
      inventory.push_back("sword");
      inventory.push_back("potion");
      cout << "You pick them up and prepare to explore.\n\n";
  
      
    // First major path choice
    int firstChoice;
    cout << "Two paths ahead:\n";
    cout << "1. Narrow path (dark, suspicious)\n";
    cout << "2. Lit corridor (louder, torches flicker)\n";
    cout << "Choose your path (1 or 2): ";

    while (!(cin >> firstChoice) || (firstChoice != 1 && firstChoice != 2)) {
        cout << "Invalid input. Please enter 1 or 2: ";
        clearInput();
    }

    if (firstChoice == 1) {
        // Expanded Beast Encounter with 3 choices
        cout << "\nYou move through the narrow path...\n";
        cout << "A wild beast blocks your way! What will you do?\n";
        cout << "1. Fight with your sword\n";
        cout << "2. Try to sneak past\n";
        cout << "3. Throw a rock to distract it\n";
        int beastChoice;

        while (!(cin >> beastChoice) || beastChoice < 1 || beastChoice > 3) {
            cout << "Invalid input. Please enter 1, 2, or 3: ";
            clearInput();
        }

        switch (beastChoice) {
            case 1:
                if (hasItem(inventory, "sword")) {
                    cout << "\nYou bravely fight and defeat the beast, but you take some damage.\n";
                    health -= 30;
                    cout << "Health now: " << health << "\n";
                } else {
                    cout << "You try to fight with your bare hands... but you're overpowered.\n";
                    cout << "You died.\n";
                    return 0;
                }
                break;
            case 2:
                cout << "You attempt to sneak, but the beast hears you...\n";
                health -= 70;
                if (health <= 0) {
                    cout << "The beast mauls you. You didn’t make it.\n";
                    return 0;
                }
                cout << "You barely escape with your life! Health: " << health << "\n";
                break;
            case 3:
                cout << "You throw a rock into the shadows. The beast runs after it.\n";
                cout << "You quietly slip by. Well done!\n";
                break;
        }

    } else {
        // Expanded Healing Fountain with 3 choices
        cout << "\nYou take the lit corridor and find a glowing healing fountain.\n";
        cout << "What do you want to do?\n";
        cout << "1. Drink from it\n";
        cout << "2. Fill your potion bottle\n";
        cout << "3. Leave it alone\n";
        int drinkChoice;

        while (!(cin >> drinkChoice) || drinkChoice < 1 || drinkChoice > 3) {
            cout << "Invalid input. Enter 1, 2, or 3: ";
            clearInput();
        }

        if (drinkChoice == 1) {
            cout << "You drink and feel your health restored.\n";
            health = 100;
        } else if (drinkChoice == 2) {
            if (!hasItem(inventory, "extra potion")) {
                cout << "You fill a bottle with glowing liquid. Gained: extra potion.\n";
                inventory.push_back("extra potion");
            } else {
                cout << "You already filled a bottle earlier.\n";
            }
        } else {
            cout << "You decide not to trust mysterious magic today.\n";
        }
    }
