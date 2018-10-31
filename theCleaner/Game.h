#pragma once
#include <vector>
#include <iostream>
#include <time.h>
#include <string>


class Game
{
public:
	Game();

	// Game Loop
	bool isPlaying = false;


	// items
	std::vector<std::string> vItems{"Nothing", "Broom", "Bucket", "Water", "Chemicals", "Mop"};
	int item;
	bool broom = false;
	bool bucket = false;
	bool waterInBucket = false;
	bool chemicals = false;
	bool mop = false;
	bool hBroom = false;
	bool hBucket = false;
	bool hWaterInBucket = false;
	bool hChemicals = false;
	bool hMop = false;
	const enum eItems
	{
		BROOM = 1,
		BUCKET,
		WATER,
		CHEM,
		MOP
	};

	// Locations
	const enum loc
	{
		EXIT,
		STORAGE,
		OFFICE,
		HALL,
		KITCHEN,
		CLEAN
	};
	
	// Functions
	void PrintMenu();
	int getChoice();
	void Playing();
	void Inventory();
	void Item();
	void Storage();
	void Office();
	void Hall();
	void Kitchen();
	


	~Game();
};
