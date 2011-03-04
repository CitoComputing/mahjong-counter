#include <string>

#include "TileSet.h"
#include "Player.h"
#include "Database.h"

class Game
{
public:
	Game(Database* db);
	void commit();
	void save();
	void end();
	std::string status();

	Player* p1;
	Player* p2;
	Player* p3;
	Player* p4;
private:
	Database* db;
};
