#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

using namespace std;


Player::Player()
{
	pPlayerLocation = mStart;
}

void Player::playerInventory()
{
	for (int i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl;
	}
}

void Player::addToInventory(string item)
{
	if (inventory.size() <= 5)
	{
		inventory.push_back(item);
		cout << item << " has been added to your inventory.\n";
	}
	else
		cout << "Your inventory is full. To pick up this item you must drop one first.\n";
}

bool Player::deleteFromInventory(string item)
{
	bool exists = false;
	for (int i = 0; i < inventory.size(); ++i)
	{
		if (inventory[i] == item)
		{
			inventory.erase(inventory.begin() + i);
			cout << "You dropped the " << item << ".\n";
			exists = true;
		}
	}
	return exists;
}

void Player::checkForKey(bool* hasRedKey, bool* hasBlueKey, bool* hasGreenKey, bool* hasYellowKey, bool* hasFlashlight, bool* hasUniform)
{
	for (int i = 0; i < inventory.size(); ++i)
	{
		if (inventory[i] == "red key")
		{
			*hasRedKey = true;
		}

		if (inventory[i] == "blue key")
		{
			*hasBlueKey = true;
		}

		if (inventory[i] == "green key")
		{
			*hasGreenKey = true;
		}
		if (inventory[i] == "yellow key")
		{
			*hasYellowKey = true;
		}
		if (inventory[i] == "flashlight")
		{
			*hasFlashlight = true;
		}
		if (inventory[i] == "uniform")
		{
			*hasUniform = true;
		}
	}
}

//Player::~Player()
//{
//	//delete pPlayer;
//}