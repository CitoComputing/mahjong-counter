#include "Database.h"
#include "TileSet.h"

class Player
{
public:
	Player(Database* db);
	~Player();
	void reset();
	void push(const int& argc, char* argv[]);
	TileSet* get(int i);
	const int& count();

	int runningScore; // The score of the whole game
private:
	Database* db;
	int setNo; // The last set filled
	TileSet* set1; TileSet* set2; TileSet* set3; TileSet* set4;
	TileSet* set5; TileSet* set6; TileSet* set7; TileSet* set8; // Pungs, Chows, Kongs or Doubles
};
