#pragma once
#include "Organism.h"

using namespace std;

class Plant : public Organism
{
	public:
		Plant();	
		Plant(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength);
		Plant(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength, vector<Lifespan> ancestorLifespans);
		void move(Position position) override;
		bool interactsWith(string species) override;
};

