#include <iostream>
#include <stdio.h>
#include <string.h>

#include "actionInit.h"
#include "TileSet.h"
#include "Database.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc >= 3 && strcmp(argv[1], "init") == 0)
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

	if(argc >= 5 && strcmp(argv[2], "add") == 0)
	{
		char dbName[50];
		strcpy(dbName, argv[1]);
		strcat(dbName, ".db");
		Database* db = new Database(dbName);

		TileSet setTest;
		setTest.set(argc, argv);
		cout << setTest.toString() << endl;

		// Player number check
		// if(strcmp(argv[3], "1") == 0))
		// if(strcmp(argv[3], "2") == 0))
		// if(strcmp(argv[3], "3") == 0))
		// if(strcmp(argv[3], "4") == 0))

		delete db;
	}

	return 0;
}
