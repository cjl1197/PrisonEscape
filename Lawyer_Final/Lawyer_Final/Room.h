//#pragma once
#include <string>
#include <vector>
using namespace std;

class Room
{
public:

	Room(string name, string description, string look,  string a, string b, string c, string d, string e);
	string pRoomName();
	void pRoomLook();
	void pRoomDescription();
	void pRoomInventory(bool* sinkExamined, bool* deskExamined, string room, bool* tileExamined);
	void deleteFromRoomInventory(string item, bool* exists, bool* red, bool* blue, bool* green, bool* yellow, bool* sinkExamined, bool* deskExamined, bool* tileExamined);
	void addToRoomInventory(string item);

	Room* pEast;
	Room* pWest;
	Room* pNorth;
	Room* pSouth;
	Room* pDown;

	vector<string> inventory;


private:
	
	string rName;
	string rDescription;
	string rLook;
};