//#pragma once
#include <iostream>
#include <string>

using namespace std;


void helpMenu()
{
	cout << "\nUse the following commands(Not case sensitive) to help you navigate the game.\n";
	cout << "\nLook:\t\t Will describe the what you can see in the room.\n";
	cout << "Examine:\t Will examine objects more closely.\n";
	cout << "Inventory or I:\t Will show the player inventory\n";
	cout << "East or E:\t Will move your player east.\n";
	cout << "West or W:\t Will move your player west.\n";
	cout << "North or N:\t Will move your player north.\n";
	cout << "South or S:\t Will move your player south.\n";
	cout << "Take:\t\t Plus a single word (noun) for the item to pick up.\n";
	cout << "Drop:\t\t Plus a single word (noun) for the item to drop.\n";

}
