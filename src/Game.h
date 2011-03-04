#include <string>

#include "TileSet.h"
#include "TileType.h"
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
	void load();

	Player* p1;
	Player* p2;
	Player* p3;
	Player* p4;

	int playerEast;
	TileType pWind;
private:
	Database* db;
};
