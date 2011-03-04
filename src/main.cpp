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
		}

		if(strcmp(argv[3], "2") == 0)
		{
			game.p2->push(argc, argv);
		}

		if(strcmp(argv[3], "3") == 0)
		{
			game.p3->push(argc, argv);
		}

		if(strcmp(argv[3], "4") == 0)
		{
			game.p4->push(argc, argv);
		}

		game.save();

		delete db;
	}

	if(argc >= 3 && strcmp(argv[2], "commit") == 0)
	{
		Database* db = new Database(argv[1]);
		Game game(db);

		cout << "Ending Round" << endl;

		game.commit();
		game.save();

		delete db;
	}

	if(argc >= 3 && strcmp(argv[2], "end") == 0)
	{
		Database* db = new Database(argv[1]);
		Game game(db);

		cout << "Ending Game" << endl;

		game.end();
		game.save();

		delete db;
	}

	if(argc >= 3 && strcmp(argv[2], "stat") == 0)
	{
		Database* db = new Database(argv[1]);
		Game game(db);

		cout << game.status();
		game.save();

		delete db;
	}

	if(argc >= 3 && strcmp(argv[2], "reset") == 0)
	{
		Database* db = new Database(argv[1]);
		Game game(db);

		// Player number check
		if(strcmp(argv[3], "1") == 0)
		{
			cout << "Reset Player 1" << endl;
			game.p1->reset();
		}

		if(strcmp(argv[3], "2") == 0)
		{
			cout << "Reset Player 2" << endl;
			game.p2->reset();
		}

		if(strcmp(argv[3], "3") == 0)
		{
			cout << "Reset Player 3" << endl;
			game.p3->reset();
		}

		if(strcmp(argv[3], "4") == 0)
		{
			cout << "Reset Player 4" << endl;
			game.p4->reset();
		}

		game.save();

		delete db;
	}

	return 0;
}
