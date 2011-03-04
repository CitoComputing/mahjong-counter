#ifndef __COUNTER_H
#define __COUNTER_H

#include <string>

#include "Player.h"

class Counter
{
public:
	Counter(Player* p);
	int getScore(bool &isOk);
	std::string toString(bool &isOk);
private:
	Player* player;

};

#endif
