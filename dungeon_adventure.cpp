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

