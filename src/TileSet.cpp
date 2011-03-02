#include <string.h>
#include <iostream>
#include "TileSet.h"

TileSet::TileSet()
{
	// Set allow season tiles to false
	f1 = false; f2 = false; f3 = false; f4 = false;
	s1 = false; s2 = false; s3 = false; s4 = false;

	// Set enums to blank
	tileType = tileBlank;
	setType = setBlank;
}

bool TileSet::set(const int& argc, char* argv[])
{
	if(argc > 5) // mc game1 add playno etc
	{
		// Loop through every command after the second, as this is the command
		for(int i = 4; i < argc; i++)
		{
			bool ignoreSecond = false;
			if(strlen(argv[i]) > 2) // It is more than 2 chars long, because -- is 2 chars long
			{
				char dash[3];
				strncpy(dash, argv[i], 2);
				dash[2] = '\0';

				if(strcmp(dash, "--") == 0)
				{
					ignoreSecond = true; // The command is a -- not -

					// It is a -- argument
					char* command = new char[strlen(argv[i]) - 2 + 1]; // -2 for the -- and +1 for the \0
					strncpy(command, argv[i] + 2, strlen(argv[i]) - 2); // Get the string without --
					command[strlen(argv[i]) - 2] = '\0'; // Add terminator

					// Main Tile Types
					if(strcmp(command, "circle") == 0)
						tileType = circle;

					if(strcmp(command, "bamboo") == 0)
						tileType = bamboo;

					if(strcmp(command, "character") == 0)
						tileType = character;

					if(strcmp(command, "east") == 0)
						tileType = east;

					if(strcmp(command, "west") == 0)
						tileType = west;

					if(strcmp(command, "north") == 0)
						tileType = north;

					if(strcmp(command, "south") == 0)
						tileType = south;

					if(strcmp(command, "red") == 0)
						tileType = red;

					if(strcmp(command, "green") == 0)
						tileType = green;

					if(strcmp(command, "white") == 0)
						tileType = white;

					// Flowers --f1 (flower 1) or --b1 (blue 1)
					if(strcmp(command, "f1") == 0 or strcmp(command, "b1") == 0)
						f1 = true;

					if(strcmp(command, "f2") == 0 or strcmp(command, "b2") == 0)
						f2 = true;

					if(strcmp(command, "f3") == 0 or strcmp(command, "b3") == 0)
						f3 = true;

					if(strcmp(command, "f4") == 0 or strcmp(command, "b4") == 0)
						f4 = true;

					// Seasons --s1 (season 1) or --r1 (red 1)
					if(strcmp(command, "s1") == 0 or strcmp(command, "r1") == 0)
						s1 = true;

					if(strcmp(command, "s2") == 0 or strcmp(command, "r2") == 0)
						s2 = true;

					if(strcmp(command, "s3") == 0 or strcmp(command, "r3") == 0)
						s3 = true;

					if(strcmp(command, "s4") == 0 or strcmp(command, "r4") == 0)
						s4 = true;

					delete command;
				}
			}

			if (strlen(argv[i]) > 1 && !ignoreSecond) // It is more than 1 char long, because - is 1 char long
			{
				char dash[2];
				strncpy(dash, argv[i], 1);
				dash[1] = '\0';

				if(strcmp(dash, "-") == 0)
				{
					// It is a - argument
					char* command = new char[strlen(argv[i])  - 1 + 1]; // -2 for the -- and +1 for the \0
					strncpy(command, argv[i] + 1, strlen(argv[i]) - 1); // Get the string without --
					command[strlen(argv[i]) - 1] = '\0'; // Add terminator

					for(int i = 0; i < (signed int)strlen(command); i++)
					{
						// Pung, Chow, Kong and Double
						if(strcmp(command, "P") == 0)
							setType = pung;

						if(strcmp(command, "C") == 0)
							setType = chow;

						if(strcmp(command, "K") == 0)
							setType = kong;

						if(strcmp(command, "D") == 0)
							setType = doub;
					}

					delete command;

				}
			} else { // Error: It is only 1 char
			}			
		}
	} else {
		// Error: Invalid amount of commands
		return false;
	}

	return true;
}

std::string TileSet::toString()
{
	std::string str = "";
	switch(tileType)
	{
		case tileBlank:
			str += "Type: Blank";
			break;
		case bamboo:
			str += "Type: Bamboo";
			break;
		case character:
			str += "Type: Character";
			break;
		case circle:
			str += "Type: Circle";
			break;
		case east:
			str += "Type: East Wind";
			break;
		case west:
			str += "Type: West Wind";
			break;
		case north:
			str += "Type: North Wind";
			break;
		case south:
			str += "Type: South Wind";
			break;
		case red:
			str += "Type: Red Dragon";
			break;
		case green:
			str += "Type: Green Dragon";
			break;
		case white:
			str += "Type: White Dragon";
			break;
	}

	switch(setType)
	{
		case setBlank:
			str += " and Set Type: Blank";
			str += '\n';
			break;
		case pung:
			str += " and Set Type: Pung";
			str += '\n';
			break;
		case chow:
			str += " and Set Type: Chow";
			str += '\n';
			break;
		case kong:
			str += " and Set Type: Kong";
			str += '\n';
			break;
		case doub:
			str += " and Set Type: Double";
			str += '\n';
			break;
	}

	str += "It has the following flower tiles: ";

	if(s1)
		str += "Season 1 ";
	if(s2)
		str += "Season 2 ";
	if(s3)
		str += "Season 3 ";
	if(s4)
		str += "Season 4 ";

	if(f1)
		str += "Flower 1 ";
	if(f2)
		str += "Flower 2 ";
	if(f3)
		str += "Flower 3 ";
	if(f4)
		str += "Flower 4 ";

	str += '\n';
	return str;
}
