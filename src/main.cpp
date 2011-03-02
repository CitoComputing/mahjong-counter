#include <iostream>
#include <stdio.h>
#include <string.h>

#include "actionInit.h"
#include "TileSet.h"
#include "Database.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc > 3)
	{
		if(strcmp(argv[1], "init") == 0)
		{
			char dbName[50];
			strcpy(dbName, argv[2]);
			strcat(dbName, ".db");

			Database* db = new Database(dbName);
			Init* handler = new Init(db);

			handler->run();

			delete db;
			delete handler;
		}

	}

	if(argc > 5)
	{
		if(strcmp(argv[2], "add") == 0)
		{
			// Proccess add score eg mc game1 add 3 --circle -Pc
		}
	}

	return 0;
}
