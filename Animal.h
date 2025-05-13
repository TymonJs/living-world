#pragma once
#include "Organism.h"
#include <iostream>

using namespace std;

class Animal : public Organism
{
	public:
		Animal();
		Animal(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength);
		Animal(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength, vector<Lifespan*> ancestorLifespans);
		void move(Position position) override;
		void save(ostream& out) const override;
    	void load(istream& in) override;

	private:
		Position lastPosition;
};

