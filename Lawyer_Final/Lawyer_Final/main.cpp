#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Help.h"

using namespace std;

int main()
{
	Map* GameMap;
	Player* player = new Player();
	string command;
	string item;
	string room;
	bool hasRedKey = false;
	bool* redKey = &hasRedKey;
	bool hasBlueKey = false;
	bool* blueKey = &hasBlueKey;
	bool sinkExamined = false;
	bool* pSinkExamined = &sinkExamined;
	bool deskExamined = false;
	bool* pDeskExamined = &deskExamined;
	bool tileExamined = false;
	bool* pTileExamined = &tileExamined;
	bool hasGreenKey = false;
	bool* greenKey = &hasGreenKey;
	bool hasYellowKey = false;
	bool* yellowKey = &hasYellowKey;
	bool hasFlashlight = false;
	bool* flashlight = &hasFlashlight;
	bool hasUniform = false;
	bool* uniform = &hasUniform;
	bool boothExamined = false;

	
	

	//player->pPlayerLocation->pRoomName();
	
	cout << "I'm not sure what you've done to land yourself in prison, \nbut I think it's time you escape. Look around to find things that will \nhelp you. I've included a help menu if you need it.\n\n";
	player->pPlayerLocation->pRoomDescription();

	do
	{
		cin >> command;
		//getline(cin, command);
		cout << endl;

		for (int i = 0; i < command.size(); ++i)
		{
			command[i] = tolower(command[i]);
		}

		player->checkForKey(redKey, blueKey, greenKey, yellowKey, flashlight, uniform);

		if (command == "help" || command == "h")
		{
			helpMenu();
			cout << endl;
			player->pPlayerLocation->pRoomDescription();
		}




		else if (command == "east" || command == "e")
		{
			if (player->pPlayerLocation->pRoomName() == "Cell Block A")
			{

				if (hasRedKey)
				{
					player->pPlayerLocation = player->pPlayerLocation->pEast;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the red key.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Exercise Yard")
			{

				if (hasRedKey)
				{
					player->pPlayerLocation = player->pPlayerLocation->pEast;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the red key.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Cafeteria Entrance Hallway")
			{

				if (hasBlueKey)
				{
					player->pPlayerLocation = player->pPlayerLocation->pEast;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the blue key.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Guard Shack")
			{

				if (hasBlueKey && hasUniform)
				{
					player->pPlayerLocation = player->pPlayerLocation->pEast;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the blue key and a guard's uniform.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Main Hallway")
			{

				if (hasBlueKey && hasUniform)
				{
					player->pPlayerLocation = player->pPlayerLocation->pEast;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the blue key and a guard's uniform.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Warden's Office")
				cout << "Door is locked and has an alarm. Best to find another way out!\n";

			else if (player->pPlayerLocation->pEast != 0)
			{
				player->pPlayerLocation = player->pPlayerLocation->pEast;
				player->pPlayerLocation->pRoomDescription();
			}
			else
				cout << "You can't go that direction.\n";
		}




		else if (command == "west" || command == "w")
		{
			if (player->pPlayerLocation->pRoomName() == "Exercise Yard")
			{

				if (hasRedKey)
				{
					player->pPlayerLocation = player->pPlayerLocation->pWest;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the red key.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Cafeteria Entrance Hallway")
			{

				if (hasBlueKey && hasUniform)
				{
					player->pPlayerLocation = player->pPlayerLocation->pWest;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the blue key and a guard's uniform.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Guard Shack")
			{

				if (hasBlueKey && hasUniform)
				{
					player->pPlayerLocation = player->pPlayerLocation->pWest;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the blue key and a guard's uniform.\n";
			}

			else if (player->pPlayerLocation->pRoomName() == "Main Hallway")
				cout << "Door is locked and has an alarm. Best to find another way out!\n";

			else if (player->pPlayerLocation->pWest != 0)
			{
				player->pPlayerLocation = player->pPlayerLocation->pWest;
				player->pPlayerLocation->pRoomDescription();
			}
			else
				cout << "You can't go that direction.\n";
		}





		else if (command == "north" || command == "n")
		{
			 if (player->pPlayerLocation->pRoomName() == "Exercise Yard")
			{

				if (hasRedKey)
				{
					player->pPlayerLocation = player->pPlayerLocation->pNorth;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the red key.\n";
			}
			 else if (player->pPlayerLocation->pRoomName() == "Main Entrance")
			 {

				 if (hasBlueKey && hasUniform)
				 {
					 player->pPlayerLocation = player->pPlayerLocation->pNorth;
					 player->pPlayerLocation->pRoomDescription();
				 }
				 else
					 cout << "The door is locked. Look for the blue key and a guard's uniform.\n";
			 }
			else if (player->pPlayerLocation->pNorth != 0)
			{
				player->pPlayerLocation = player->pPlayerLocation->pNorth;
				player->pPlayerLocation->pRoomDescription();
			}
			else
				cout << "You can't go that direction.\n";
		}





		else if (command == "south" || command == "s")
		{
			if (player->pPlayerLocation->pRoomName() == "Exercise Yard")
			{

				if (hasYellowKey)
				{
					player->pPlayerLocation = player->pPlayerLocation->pSouth;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the yellow key.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Main Hallway")
			{

				if (hasBlueKey && hasUniform)
				{
					player->pPlayerLocation = player->pPlayerLocation->pSouth;
					player->pPlayerLocation->pRoomDescription();
				}
				else
					cout << "The door is locked. Look for the blue key and a guard's uniform.\n";
			}
			else if (player->pPlayerLocation->pRoomName() == "Main Entrance")
			{

				if (hasBlueKey && hasUniform)
				{
					cout << "Congradulations! A get away driver was waiting and you have escaped! Hope you enjoyed your stay!!  ;)\n";
					cout << "Type quit to exit the game.\n";
					player->pPlayerLocation = player->pPlayerLocation->pSouth;
					
				}
				else
					cout << "The door is locked. Look for the blue key and a guard's uniform.\n";
			}				

			else if (player->pPlayerLocation->pSouth != 0)
			{
				player->pPlayerLocation = player->pPlayerLocation->pSouth;
				player->pPlayerLocation->pRoomDescription();
			}
				else
					cout << "You can't go that direction.\n";
			}





		else if (command == "down" || command == "d")
		{
			if (player->pPlayerLocation->pDown != 0)
			{
				player->pPlayerLocation = player->pPlayerLocation->pDown;
				player->pPlayerLocation->pRoomDescription();
			}
			else
				cout << "You can't go that direction.\n";
		}





		else if (command == "look")
		{

			if (player->pPlayerLocation->pRoomName() == "Cell Block A Showers")
				room = "aShowers";

			if (player->pPlayerLocation->pRoomName() == "Warden's Office")
				room = "office";

			if (player->pPlayerLocation->pRoomName() == "Cell Block B Showers")
				room = "bShowers";
			
			if (player->pPlayerLocation->pRoomName() == "Chapel" && !hasFlashlight)
				cout << "It's too dark. You can't see anything and the lights don't seem to work.\n";
			
			else
			{
				player->pPlayerLocation->pRoomLook();

				if (player->pPlayerLocation->inventory.size() != 0)
				{
					//cout << "You also see: \n";
					player->pPlayerLocation->pRoomInventory(pSinkExamined, pDeskExamined, room, pTileExamined);
				}
			}
		}





		else if (command == "examine")
		{
			string object;

			cin >> object;

			if (player->pPlayerLocation->pRoomName() == "Cell Block A Showers")
			{
				if (object == "sink" || object == "sinks")
				{
					cout << "You see a red key taped to the bottom of a the sink.\n";
					sinkExamined = true;
				}
				else
					cout << "There is nothing of interest there.\n";
			}

			if (player->pPlayerLocation->pRoomName() == "Cell Block B Showers")
			{
				if (object == "tile")
				{
					cout << "You see a screwdriver hidden behind the tile.\n";
					tileExamined = true;
				}
				else
					cout << "There is nothing of interest there.\n";
			}

			if (player->pPlayerLocation->pRoomName() == "Warden's Office")
			{
				if (object == "desk" && hasGreenKey)
				{
					cout << "You see a blue key in the desk drawer.\n";
					deskExamined = true;
				}
				else if (object == "desk" && !hasGreenKey)
					cout << "The desk is locked. You need to find the green key.";
				else
					cout << "There is nothing of interest there.\n";
			}

			if (player->pPlayerLocation->pRoomName() == "Chapel")
			{
				if (object == "booth")
					cout << "There's a hole in the bottom of the confession booth that has\na ladder leading down. I wonder where it goes?\n";
			}
		}





		else if (command == "inventory" || command == "i")
		{
			if (player->inventory.size() == 0)
			{
				cout << "Your inventory is empty.\n";
			}
			else
				player->playerInventory();
		}





		else if (command == "take")
		{
			bool exists = false;
			bool red = false;
			bool blue = false;
			bool green = false;
			bool yellow = false;
			bool* pExists = &exists;
			bool* pRed = &red;
			bool* pBlue = &blue;
			bool* pGreen = &green;
			bool* pYellow = &yellow;
			string color;
			

			if (player->inventory.size() == 5)
			{
				cout << "Your inventory is full. You must drop something to pick up something else.\n";
			}

			else
			{
				cin >> item;

				for (int i = 0; i < item.size(); ++i)
				{
					item[i] = tolower(item[i]);
				}
				
				player->pPlayerLocation->deleteFromRoomInventory(item, pExists, pRed, pBlue, pGreen, pYellow, pSinkExamined, pDeskExamined, pTileExamined);

				if (item == "key" && exists)
				{
					if (red)
						item = "red key";

					else if (blue)
						item = "blue key";

					else if (green)
						item = "green key";

					else if (yellow)
						item = "yellow key";
					
				
					player->addToInventory(item);
					//cout << item << " has been added to your inventorty.\n";
				}
				else if (item != "key")
					player->addToInventory(item);
				else
					cout << "\nSorry, but I don't understand what you mean. Please see the help menu if you're having problems.\n";
			}
		}






		else if (command == "drop")
		{
			string key;
			bool exists = false;

			if (player->inventory.size() == 0)
				cout << "Your inventory is empty.\n";

			else
			{
				cin >> item;

				if (item == "red")
				{
					cout << "\nSorry, but I don't understand what you mean. Please see the help menu if you're having problems.\n";
					continue;
				}
				else if (item == "blue")
				{
					cout << "\nSorry, but I don't understand what you mean. Please see the help menu if you're having problems.\n";
					continue;
				}
				else if (item == "green")
				{
					cout << "\nSorry, but I don't understand what you mean. Please see the help menu if you're having problems.\n";
					continue;
				}
				else if (item == "yellow")
				{
					cout << "\nSorry, but I don't understand what you mean. Please see the help menu if you're having problems.\n";
					continue;
				}
				else if (item == "key")
				{
					cout << "Which key would you like to drop?\n";
					cin >> key;

					for (int i = 0; i < key.size(); ++i)
					{
						key[i] = tolower(key[i]);
					}

					if (key == "red")
					{
						item = "red key";
						hasRedKey = false;
					}
					if (key == "blue")
					{
						item = "blue key";
						hasBlueKey = false;
					}
					if (key == "green")
					{
						item = "green key";
						hasGreenKey = false;
					}
					if (key == "yellow")
					{
						item = "yellow key";
						hasYellowKey = false;
					}
				
				}

				for (int i = 0; i < item.size(); ++i)
				{
					item[i] = tolower(item[i]);
				}
				if (item == "flashlight")
					hasFlashlight = false;
				if (item == "uniform")
					hasUniform = false;

				exists = player->deleteFromInventory(item);
				if (exists)
				{
					player->pPlayerLocation->addToRoomInventory(item);
				}
				else
					cout << "Item doesn't exist in your inventory\n";
			}
		}






		else if (command == "quit" || command == "q")
			cout << "Thanks for playing!!\n";

		else
			cout << "Enter a valid command or quit to exit.\n";

		cout << endl;

	} while (command != "quit" && command != "q");


	return 0;
}