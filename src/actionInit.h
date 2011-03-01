#include <string>
#include "Database.h"

class Init
{
public:
	Init(Database* db);
	void run();
private:
	Database* db;
};
