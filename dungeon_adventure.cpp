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
  