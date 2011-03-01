#include <iostream>
#include <stdio.h>
#include <string.h>

#include "actionInit.h"
#include "Database.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc > 2)
	{
		if(strcmp(argv[1], "init") == 0)
		{
			char dbName[50];
			strcpy(dbName, argv[2]);
			strcat(dbName, ".db");

			Database* db = new Database(dbName);
			Init* handler = new Init(db);

			handler->run();
		}
	}

	return 0;
}
