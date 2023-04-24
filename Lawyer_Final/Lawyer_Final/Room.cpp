#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

Room::Room(string name, string description, string look,  string a, string b, string c, string d, string e)
{
	rName = name;
	rDescription = description;
	rLook = look;
	inventory.push_back(a);
	inventory.push_back(b);
	inventory.push_back(c);
	inventory.push_back(d);
	inventory.push_back(e);
}

string Room::pRoomName()
{
	//cout << rName << endl;

	return rName;
}

void Room::pRoomLook()
{
	cout << rLook << endl;
}

void Room::pRoomDescription()
{
	cout << rDescription << endl;
}

void Room::pRoomInventory(bool* sinkExamined, bool* deskExamined, string room, bool* tileExamined)
{
	//cout << "\n" << rName << " contains: \n\n";
	if (inventory.size() > 0)
		cout << "You also see: \n";
	
	for (int i = 0; i < inventory.size(); ++i)
	{
		if (!*sinkExamined && room == "aShowers")
		{
			if (inventory[i] != "red key" && inventory[i] != "")
				cout << inventory[i] << endl;
		}
		else if (!*deskExamined && room == "office")
		{
			if (inventory[i] != "blue key" && inventory[i] != "")
				cout << inventory[i] << endl;
		}
		else if (!*tileExamined && room == "bShowers")
		{
			if (inventory[i] != "screwdriver" && inventory[i] != "")
				cout << inventory[i] << endl;
		}

		else if (inventory[i] != "")
			cout << inventory[i] << endl;
	}
}

void Room::deleteFromRoomInventory(string item, bool* pExists, bool* pRed, bool* pBlue, bool* pGreen, bool* pYellow, bool* sinkExamined, bool* deskExamined, bool* tileExamined)
{
	bool keys = false;
	int numKeys = 0;
	string color;

	for (int i = 0; i < inventory.size(); ++i)
	{
		if (inventory[i] == "red key" || inventory[i] == "blue key" || inventory[i] == "green key" || inventory[i] == "yellow key")
		{
			++ numKeys;
		}
	}

	if (numKeys > 1)
		keys = true;

	if (keys && item == "key")
	{
		cout << "Which key would you like to take?\n";
		cin >> color;
		item = color + ' ' + item;

		if (color == "red")
			*pRed = true;
		else if (color == "blue")
			*pBlue = true;
		else if (color == "green")
			*pGreen = true;
		else if (color == "yellow")
			*pYellow = true;


		for (int i = 0; i < inventory.size(); ++i)
		{
			if (inventory[i] == item)
			{
				inventory.erase(inventory.begin() + i);
				*pExists = true;
			}
		}
	}

	else
	{
		for (int i = 0; i < inventory.size(); ++i)
		{
			if (item == "key")
			{
				if (inventory[i] == "red key" && *sinkExamined)
				{
					item = "red key";
					*pRed = true;
				}

				if (inventory[i] == "blue key" && *deskExamined)
				{
					item = "blue key";
					*pBlue = true;
				}

				if (inventory[i] == "green key")
				{
					item = "green key";
					*pGreen = true;
				}

				if (inventory[i] == "yellow key")
				{
					item = "yellow key";
					*pYellow = true;
				}


			}

			if (inventory[i] == "screwdriver")
			{
				if (*tileExamined)
				{
					inventory.erase(inventory.begin() + i);
					*pExists = true;
				}
			}

			else if (inventory[i] == item)
			{
				inventory.erase(inventory.begin() + i);
				*pExists = true;
			}
		}
	}
}

void Room::addToRoomInventory(string item)
{
	inventory.push_back(item);
}
