#include <iostream>
#include "Player.h"

Player::Player(Database* db)
{
	this->db = db;
	reset(); // Initialize all variables
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

void Player::setSet(const int& argc, char* argv[])
{
	switch(setNo)
	{
		case 0:
			set1->set(argc, argv);
		case 1:
			set2->set(argc, argv);
		case 2:
			set3->set(argc, argv);
		case 3:
			set4->set(argc, argv);
		case 4:
			set5->set(argc, argv);
		case 5:
			set6->set(argc, argv);
		case 6:
			set7->set(argc, argv);
		case 7:
			set8->set(argc, argv);
		case 8:
			std::cout << "Too many sets! Please reset this player before adding more!" << std::endl;
			return;
	}
}

TileSet* Player::getSet(int i)
{
}

const int& Player::getSetCount()
{
	return setNo;
}
