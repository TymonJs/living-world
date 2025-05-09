#pragma once
#include "Organism.h"

using namespace std;

class Plant : public Organism
{
	public:
		Plant(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength);
		Plant();
		void move(Position position) override;
		bool interactsWith(string species) override;
};

