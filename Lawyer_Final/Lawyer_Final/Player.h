//#pragma once
#include <string>
#include <vector>
#include "Map.h"

using namespace std;

class Player : public Map
{
public:
	vector<string> inventory;

	Player();
	//~Player();
	void playerInventory();
	void addToInventory(string item);
	bool deleteFromInventory(string item);
	void checkForKey(bool* hasRedKey, bool* hasBlueKey, bool* hasGreenKey, bool* hasYellowKey, bool* hasFlashlight, bool* hasUniform);

	Room* pPlayerLocation;

};
