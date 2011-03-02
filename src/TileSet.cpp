#include <string.h>
#include <iostream>
#include "TileSet.h"

TileSet::TileSet()
{
	// Set allow season tiles to false
	f1 = false; f2 = false; f3 = false; f4 = false;
	s1 = false; s2 = false; s3 = false; s4 = false;
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

					// command is the command to be proccessed for -- eg circle

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

					// command is the command to be proccessed for - eg pong

					delete command;

				}
			} else { // Error: It is only 1 char
			}			
		}
	} else {
		// Error: Invalid amount of commands
	}
}
