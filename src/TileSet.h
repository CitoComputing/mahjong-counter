#include "TileType.h"

class TileSet
{
public:
	TileSet();
	bool set(const int& argc, char* argv[]);
private:
	TileType tileType;
	SetType setType;
	bool s1, s2, s3, s4;
	bool f1, f2, f3, f4;
};
