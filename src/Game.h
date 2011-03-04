#include "TileSet.h"
#include "Player.h"
#include "Database.h"

class Game
{
public:
	Game(Database* db);
	void commit();
	void end();

	Player* p1;
	Player* p2;
	Player* p3;
	Player* p4;
private:
	Database* db;
};
