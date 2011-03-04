#include <iostream>
#include "Player.h"

Player::Player(Database* db)
{
	this->db = db;
	reset(); // Initialize all variables
	runningScore = 0;
}

Player::~Player()
{
	delete set1; delete set2; delete set3; delete set4;
	delete set5; delete set6; delete set7; delete set8;
}

void Player::reset()
{
	// Re-Initialize all variables
	setNo = 0;
	set1 = new TileSet(); set2 = new TileSet(); set3 = new TileSet(); set4 = new TileSet();
	set5 = new TileSet(); set6 = new TileSet(); set7 = new TileSet(); set8 = new TileSet();
}

void Player::push(const int& argc, char* argv[])
{
	switch(setNo)
	{
		case 0:
			set1->set(argc, argv);
			break;
		case 1:
			set2->set(argc, argv);
			break;
		case 2:
			set3->set(argc, argv);
			break;
		case 3:
			set4->set(argc, argv);
			break;
		case 4:
			set5->set(argc, argv);
			break;
		case 5:
			set6->set(argc, argv);
			break;
		case 6:
			set7->set(argc, argv);
			break;
		case 7:
			set8->set(argc, argv);
			break;
		case 8:
			std::cout << "Too many sets! Please reset this player before adding more!" << std::endl;
			return;
	}
}

bool Player::commit()
{
	// Add score too running total and then reset
	return true;
}

void Player::load()
{
	// Load from database
}

TileSet* Player::get(int i)
{
	switch(setNo)
	{
		case 0:
			return set1;
		case 1:
			return set2;
		case 2:
			return set3;
		case 3:
			return set4;
		case 4:
			return set5;
		case 5:
			return set6;
		case 6:
			return set7;
		case 7:
			return set8;
	}

	return 0;
}

const int& Player::count()
{
	return setNo;
}
