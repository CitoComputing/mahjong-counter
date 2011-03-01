#include <string>
#include <iostream>
#include "actionInit.h"

Init::Init(Database* db)
{
	this->db = db;
}

void Init::run()
{
	// Create tables
	db->query("CREATE TABLE IF NOT EXISTS config (id INTEGER PRIMARY KEY AUTOINCREMENT, name, value)");

	std::cout << "Created initial database" << std::endl;
}
