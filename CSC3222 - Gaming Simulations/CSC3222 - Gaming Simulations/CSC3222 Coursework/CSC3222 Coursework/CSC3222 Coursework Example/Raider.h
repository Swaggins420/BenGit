#pragma once
#include "Entity.h"
#include <vector>
#include "Dragon.h"

using std::vector;

class Raider : public Entity {
public:
	Raider();
	virtual ~Raider();

	int countRaidersInRange(vector<Raider> raiders, Dragon dragon);
	//void orientRaiders(vector<Raider> raiders, Dragon dragon, int numRaiders);
	vector<Raider> raidersInRange;

	Entity* get() { return this; };
private:

};