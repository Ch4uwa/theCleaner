#include "pch.h"
#include "Game.h"


Game::Game()
	:isPlaying(true), item(0)
{
	
}

// Prints Menu
void Game::PrintMenu()
{
	std::cout << " Where to look?\n"
		<< "\n"
		<< "1. Storage\n"
		<< "2. Office\n"
		<< "3. Hall\n"
		<< "4. Kitchen\n"
		<< "5. Clean\n"
		<< "0. Exit\n";
}

// User input getter/handler
int Game::getChoice()
{
	int choice;
	std::cout << "Your choice: ";
	while (!(std::cin >> choice))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Your choice: ";
	}
	std::cin.ignore();
	return choice;
}

// Main switch "The Game"
void Game::Playing()
{
	
	Inventory();
	std::cout << "\n";
	PrintMenu();
	
	switch (getChoice())
	{
	case STORAGE:
		Storage();
		break;
	case OFFICE:
		Office();
		break;
	case HALL:
		Hall();
		break;
	case KITCHEN:
		Kitchen();
		break;
	case CLEAN:
		
		if (bucket && broom && chemicals && mop && waterInBucket)
		{
			isPlaying = false;
			std::cout << "You win one more day at your job!\n";
			std::cin.get();
		}
		else
		{
			std::cout << "\nYou can't clean yet, need more stuff!\n";
		}
		
		break;
	case EXIT:
		isPlaying = false;
		break;
	default:
		std::cout << "Wrong work place.";
		break;
	}
	if (bucket && broom && chemicals && mop && waterInBucket)
	{
		system("cls");
		isPlaying = false;
		std::cout << "You win one more day at your job!";
		std::cin.get();
	}
}

// Printing item name that have been picked up.
void Game::Inventory()
{
	const int x = 50;
	int i = 0;
	std::cout << "\n" << std::string(x, ' -') << "\n";
	std::cout << "Cleaning cart ==> ";
	if (broom)
	{
		i++;
		std::cout << vItems[1] << ", ";
	}
	if (bucket)
	{
		i++;
		std::cout << vItems[2] << ", ";
	}
	if (waterInBucket)
	{
		i++;
		std::cout << vItems[3] << ", ";
	}
	if (chemicals)
	{
		i++;
		std::cout << vItems[4] << ", ";
	}
	if (mop)
	{
		i++;
		std::cout << vItems[5] << ", ";
	}
	std::cout << "\n" << i << " / " << (vItems.size()-1) << "\n";
	std::cout << "\n" << std::string(x, ' -') << "\n";
}

// Spawns item in random room.
void Game::Item()
{
	item = (1 + (rand() % 5));
	
	switch (item)
	{
	case BROOM:
		broom = true;
		break;
	case BUCKET:
		bucket = true;
		break;
	case WATER:
		if (bucket)
		{
			waterInBucket = true;
		}
		break;
	case CHEM:
		chemicals = true;
		break;
	case MOP:
		mop = true;
		break;
	}
}

// Check if you have item when entering a room. And pick it up.
void Game::Storage()
{

	Item();
	if (item == 1 && !hBroom)
	{
		std::cout << "It's a storage room, with stuff.\nYou find a broom good for you\n";
		hBroom = true;
	}
	if (item == 2 && !hBucket)
	{
		std::cout << "It's a storage room, with stuff.\nYou find a bucket nice\n";
		hBucket = true;
	}
	if (item == 3 && !hWaterInBucket)
	{
		std::cout << "It's a storage room, with stuff.\nYou find some water\n";
		if (hBucket)
		{
			hWaterInBucket = true;
		}
		else
		{
			std::cout << "But you need something to put it in!";
		}
	}
	if (item == 4 && !hChemicals)
	{
		std::cout << "It's a storage room, with stuff.\nYou find the chemicals dont drink it\n";
		hChemicals = true;
	}
	if (item == 5 && !hMop)
	{
		std::cout << "It's a storage room, with stuff.\nYou find a mop good for you\n";
		hMop = true;
	}
	std::cout << "Keep Looking.\n\n";

}
void Game::Office()
{
	Item();
	if (item == 1 && !hBroom)
	{
		std::cout << "Your bosses office, with his stuff.\nYou find a broom good for you\n";
		hBroom = true;
	}
	if (item == 2 && !hBucket)
	{
		std::cout << "Your bosses office, with his stuff.\nYou find a bucket nice\n";
		hBucket = true;
	}
	if (item == 3 && !hWaterInBucket)
	{
		std::cout << "Your bosses office, with his stuff.\nYou find some water\n";
		if (hBucket)
		{
			hWaterInBucket = true;
		}
		else
		{
			std::cout << "But you need something to put it in!";
		}
	}
	if (item == 4 && !hChemicals)
	{
		std::cout << "Your bosses office, with his stuff.\nYou find the chemicals dont drink it\n";
		hChemicals = true;
	}
	if (item == 5 && !hMop)
	{
		std::cout << "Your bosses office, with his stuff.\nYou find a broom good for you\n";
		hMop = true;
	}
	std::cout << "Keep Looking.\n\n";

}
void Game::Hall()
{
	
	std::cout << "It's a hallway, without stuff.\nGo to some room and look.\n";

}
void Game::Kitchen()
{
	Item();
	if (item == 1 && !hBroom)
	{
		std::cout << "In the kitchen you find your broom good for you\n";
		hBroom = true;
	}
	if (item == 2 && !hBucket)
	{
		std::cout << "In the kitchen you find your bucket great\n";
		hBucket = true;
	}
	if (item == 3 && !hWaterInBucket)
	{
		std::cout << "In the kitchen there is water, always good to have\n";
		if (hBucket)
		{
			hWaterInBucket = true;
		}
		else
		{
			std::cout << "But you need something to put it in!\n";
		}
	}
	if (item == 4 && !hChemicals)
	{
		std::cout << "In the kitchen you find chemicals?? why? a well\n";
		hChemicals = true;
	}
	if (item == 5 && !hMop)
	{
		std::cout << "In the kitchen you find your mop\n";
		hMop = true;
	}

	std::cout << "Keep Looking.\n\n";
}

Game::~Game()
{
}
