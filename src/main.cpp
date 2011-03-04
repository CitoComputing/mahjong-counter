#include <iostream>
#include <stdio.h>
#include <string.h>

#include "actionInit.h"
#include "TileSet.h"
#include "Database.h"
#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc >= 3 && strcmp(argv[1], "init") == 0)
	{
		Database* db = new Database(argv[2]);
		Init* handler = new Init(db);

		handler->run();

		delete db;
		delete handler;
	}

	if(argc >= 5 && strcmp(argv[2], "add") == 0)
	{
		Database* db = new Database(argv[1]);

		Game game(db);

		// Player number check
		if(strcmp(argv[3], "1") == 0)
		{
			game.p1->push(argc, argv);
			cout << game.p1->get(game.p1->count() - 1)->toString();
		}

		if(strcmp(argv[3], "2") == 0)
		{
			game.p2->push(argc, argv);
			cout << game.p2->get(game.p2->count() - 1)->toString();
		}

		if(strcmp(argv[3], "3") == 0)
		{
			game.p3->push(argc, argv);
			cout << game.p3->get(game.p3->count() - 1)->toString();
		}

		if(strcmp(argv[3], "4") == 0)
		{
			game.p4->push(argc, argv);
			cout << game.p4->get(game.p4->count() - 1)->toString();
		}

		delete db;
	}

	return 0;
}
