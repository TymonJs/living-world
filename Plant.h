#pragma once
#include "Organism.h"

class Plant : public Organism
{
	public:
		Plant(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength);
		Plant();
};

