#include "Game.h"

Game::Game(Database* db)
{
	this->db = db;
	p1 = new Player(db); p2 = new Player(db); p3 = new Player(db); p4 = new Player(db);

	// Load all players from database
	p1->load(); p2->load(); p3->load(); p4->load();
}

void Game::commit()
{
	p1->commit();
	p2->commit();
	p3->commit();
	p4->commit();
}

void Game::end()
{
	// Display scores
}

void Game::save()
{
	// Save to db
}

std::string Game::status()
{
	return "Status";
}
