#pragma once
#include "Organism.h"

using namespace std;

class Animal : public Organism
{
	public:
		Animal(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength);
		Animal();
		void move(Position position) override;
	private:
		Position lastPosition;
};

