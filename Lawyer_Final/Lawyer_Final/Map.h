//#pragma once
#include <string>
#include <vector>
#include "Room.h"

using namespace std;

class Map
{
public:

	Map();
	~Map();
	vector<Room*> pRooms;


	Room* mStart;
	
};
