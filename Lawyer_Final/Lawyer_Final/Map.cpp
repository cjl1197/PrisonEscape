#include <iostream>
#include "Map.h"

using namespace std;

Map::Map()
{
	Room* pPlayerCell = new Room("Cell", "You are in your cell.", "There are is a bed, metal toilet and a sink. It appears as though your door was left open!", "toothbrush", "bible", "pictures", "", "");
	mStart = pPlayerCell;
	pRooms.push_back(pPlayerCell);

	Room* pCellBlockA = new Room("Cell Block A", "You are in Cell Block A.", "Not much to see here. Just a bunch of cells. Luckily all the other inmates are asleep.", "", "", "", "", "");
	pRooms.push_back(pCellBlockA);
	Room* pCBABath = new Room("Cell Block A Showers", "You are in the Cell Block A Showers.", "There are several shower stalls and a few sinks.", "red key", "soap", "towel", "", "");
	pRooms.push_back(pCBABath);
	Room* pExerciseYard = new Room("Exercise Yard", "You are in the Exercise Yard.", "Wide open area. Has a basketball court, some places to sit and not much else. Better avoid the lights. Wouldn't want to get caught.", "basketball", "cigarettes", "", "", "");
	pRooms.push_back(pExerciseYard);
	Room* pCellBlockB = new Room("Cell Block B", "You are in Cell Block B.", "Just like your cell block there isn't much to see here.", "", "", "", "", "");
	pRooms.push_back(pCellBlockB);
	Room* pCBBBath = new Room("Cell Block B Showers", "You are in the Cell Block B Showers.", "This shower room is laid out just like the one on your block. Some shower stalls and some sinks. It appears one of the shower stalls has a loose tile.", "towel", "soap", "screwdriver", "", "");
	pRooms.push_back(pCBBBath);
	Room* pRecEnt = new Room("Rec. Entrance Hallway", "You are in a hallway.", "It's a hallway, not much more to see. It has entrances into the Library, the Recreation Room and the Chapel.", "", "", "", "", "");
	pRooms.push_back(pRecEnt);
	Room* pLibrary = new Room("Library", "You are in the Library.", "What can I say...it's a library. There are many book shelves loaded with books. There are a couple computers. I bet they are monitored pretty closely.", "yellow key", "book", "lighter", "", "");
	pRooms.push_back(pLibrary);
	Room* pChapel = new Room("Chapel", "You are in the Chapel.", "Pretty much like any other church. There are some pews, a podium and various religious items from many different faiths. There is also confession booth in the corner.", "bible", "gum", "hat", "", "");
	pRooms.push_back(pChapel);
	Room* pRecRoom = new Room("Recreation Room", "You are in the Recreation Room.", "Although it's called a rec room, it's mainly just a gym with weights and excercise equipment.", "dumbell", "jump-rope", "barbell", "bottle", "");
	pRooms.push_back(pRecRoom);
	Room* pCafEnt = new Room("Cafeteria Entrance Hallway", "You are in a hallway.", "It's a hallway, not much more to see. It has entrances into the Guard Shack, the Cafeteria and the Laundry Room.", "", "", "", "", "");
	pRooms.push_back(pCafEnt);
	Room* pLaundry = new Room("Laundry", "You are in the laundry room.", "Just what you would expect. There are a lot of washing machines, dryers and ironing equipment.", "uniform", "iron", "nameplate", "", "");
	pRooms.push_back(pLaundry);
	Room* pCafeteria = new Room("Cafeteria", "You are in the cafeteria.", "Just like you had in elementary school. This room has rows of tables with built in chairs, kind of like picnic tables.", "green key", "cup", "plate", "bread", "");
	pRooms.push_back(pCafeteria);
	Room* pKitchen = new Room("Kitchen", "You are in the kitchen.", "While I'm here I might as well grab a snack. This breaking out of jail makes me hungary.There is a big fridge, several cubbards and some counters.", "flashlight", "pudding", "coffee", "", "");
	pRooms.push_back(pKitchen);
	Room* pGuardShack = new Room("Guard Shack", "You are in the guard shack.", "Can't believe they didn't leave at least one guard in here while they are on patrol. This room has a lot of camera's. Can't believe they didn't see me. There is a safe, desk and closet.", "coat", "gloves", "donuts", "", "");
	pRooms.push_back(pGuardShack);
	Room* pVisitation = new Room("Visitation Room", "You are in the visitaion room.", "This room is pretty empty. Just a couple of tables and chairs. I think this is the cleanest room in the place. Guess they don't want visitors to see what this place really looks like.", "", "", "", "", "");
	pRooms.push_back(pVisitation);
	Room* pWardensOffice = new Room("Warden's Office", "You are in the Warden's office.", "You see the Warden's desk, a closet and shelf fool of books. ", "blue key", "", "", "", "");
	pRooms.push_back(pWardensOffice);
	Room* pHallway1 = new Room("Main Hallway", "You are in a hallway.", "It's a hallway, not much more to see. It has entrances into the Warden's Office, the Main Entrance and the Guard Shack.", "", "", "", "", "");
	pRooms.push_back(pHallway1);
	Room* pMainEnt = new Room("Main Entrance", "You are in the main entrance of the prison.", "This is the main entrance to the prison. There is a desk for visitors to check in and a few seats for waiting. Not much else to see.", "", "", "", "", "");
	pRooms.push_back(pMainEnt);
	Room* pParkingLot = new Room("Parking Lot", "", "", "", "", "", "", "");
	pRooms.push_back(pParkingLot);


	// Player's Cell
	pPlayerCell->pEast = pCellBlockA;
	pPlayerCell->pWest = 0;
	pPlayerCell->pNorth = 0;
	pPlayerCell->pSouth = 0;
	pPlayerCell->pDown = 0;

	// Cell Block A
	pCellBlockA->pEast = pExerciseYard;
	pCellBlockA->pWest = pPlayerCell;
	pCellBlockA->pNorth = pCBABath;
	pCellBlockA->pSouth = 0;
	pCellBlockA->pDown = 0;

	// Cell Block B
	pCellBlockB->pWest = pExerciseYard;
	pCellBlockB->pEast = 0;
	pCellBlockB->pNorth = pCBBBath;
	pCellBlockB->pSouth = 0;
	pCellBlockB->pDown = 0;

	// Cell Block A Bathroom/Showers
	pCBABath->pWest = 0;
	pCBABath->pEast = 0;
	pCBABath->pNorth = 0;
	pCBABath->pSouth = pCellBlockA;
	pCBABath->pDown = 0;

	// Cell Block B Bathroom/Showers
	pCBBBath->pWest = 0;
	pCBBBath->pEast = 0;
	pCBBBath->pNorth = 0;
	pCBBBath->pSouth = pCellBlockB;
	pCBBBath->pDown = 0;

	// Exercise Yard
	pExerciseYard->pEast = pCellBlockB;
	pExerciseYard->pWest = pCellBlockA;
	pExerciseYard->pNorth = pRecEnt;
	pExerciseYard->pSouth = pCafEnt;
	pExerciseYard->pDown = 0;

	// Rec. Entrance Hallway
	pRecEnt->pEast = pChapel;
	pRecEnt->pWest = pLibrary;
	pRecEnt->pNorth = pRecRoom;
	pRecEnt->pSouth = pExerciseYard;
	pRecEnt->pDown = 0;

	// Library
	pLibrary->pEast = pRecEnt;
	pLibrary->pWest = 0;
	pLibrary->pNorth = 0;
	pLibrary->pSouth = 0;
	pLibrary->pDown = 0;

	// Chapel
	pChapel->pEast = 0;
	pChapel->pWest = pRecEnt;
	pChapel->pNorth = 0;
	pChapel->pSouth = 0;
	pChapel->pDown = pWardensOffice;

	// Rec Room
	pRecRoom->pEast = 0;
	pRecRoom->pWest = 0;
	pRecRoom->pNorth = 0;
	pRecRoom->pSouth = pRecEnt;
	pRecRoom->pDown = 0;

	// Cafeteria Entrance Hallway
	pCafEnt->pEast = pLaundry;
	pCafEnt->pWest = pGuardShack;
	pCafEnt->pNorth = pExerciseYard;
	pCafEnt->pSouth = pCafeteria;
	pCafEnt->pDown = 0;

	// Cafeteria
	pCafeteria->pEast = pKitchen;
	pCafeteria->pWest = 0;
	pCafeteria->pNorth = pCafEnt;
	pCafeteria->pSouth = 0;
	pCafeteria->pDown = 0;

	// Laundry
	pLaundry->pEast = 0;
	pLaundry->pWest = pCafEnt;
	pLaundry->pNorth = 0;
	pLaundry->pSouth = 0;
	pLaundry->pDown = 0;

	// Kitchen
	pKitchen->pEast = 0;
	pKitchen->pWest = pCafeteria;
	pKitchen->pNorth = 0;
	pKitchen->pSouth = 0;
	pKitchen->pDown = 0;

	// Guard Shack
	pGuardShack->pEast = pCafEnt;
	pGuardShack->pWest = pHallway1;
	pGuardShack->pNorth = 0;
	pGuardShack->pSouth = pVisitation;
	pGuardShack->pDown = 0;

	// Visitaion
	pVisitation->pEast = 0;
	pVisitation->pWest = 0;
	pVisitation->pNorth = pGuardShack;
	pVisitation->pSouth = 0;
	pVisitation->pDown = 0;

	// Hallway 1
	pHallway1->pEast = pGuardShack;
	pHallway1->pWest = 0;
	pHallway1->pNorth = 0;
	pHallway1->pSouth = pMainEnt;
	pHallway1->pDown = 0;

	// Warden's Office
	pWardensOffice->pEast = 0;
	pWardensOffice->pWest = 0;
	pWardensOffice->pNorth = 0;
	pWardensOffice->pSouth = 0;
	pWardensOffice->pDown = pChapel;

	// Main Entrance
	pMainEnt->pEast = 0;
	pMainEnt->pWest = 0;
	pMainEnt->pNorth = pHallway1;
	pMainEnt->pSouth = 0;
	pMainEnt->pDown = 0;

	// Parking Lot
	pParkingLot->pEast = 0;
	pParkingLot->pWest = 0;
	pParkingLot->pNorth = pMainEnt;
	pParkingLot->pSouth = 0;
}

Map::~Map()
{
	  
	for (int i = pRooms.size() - 1; i >= 0; --i)
	{
		cout << pRooms[i] << endl;
		delete(pRooms[i]);
		cout << pRooms[i] << endl;
	}


	
}
