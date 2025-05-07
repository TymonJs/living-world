#include <iostream>
#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Grass.h"

using namespace std;

int main()
{	
	// World test
	World world;
	Position posP1{ 4, 5 };
	Plant plantW1{ 3, posP1, 0, 0, 0, 0};
	Position posP2{ 5, 4 };
	Plant plantW2{ 3, posP2, 0, 0, 0, 0};

	Position posW2{ 3, 2 };
	Animal animalW1{ 6, posW2, 0, 0, 0, 0 };
	Position posW3{ 2, 3 };
	Animal animalW2{ 6, posW3, 0, 0, 0, 0 };

	Position postemp{0,0};
	Grass grass{postemp,0};

	world.addOrganism(&plantW1);
	world.addOrganism(&plantW2);
	world.addOrganism(&animalW1);
	world.addOrganism(&animalW2);
	world.addOrganism(&grass);
	
	auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));

	for(auto pos: positions)
		cout << pos.toString() << endl;

	// Tura 0
	cout << world.toString() << endl;

	// Tura 1
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 2
	world.makeTurn();
	cout << world.toString() << endl;

	// world.writeWorld("world.bin");

	// Tura 3
	world.makeTurn();
	cout << world.toString() << endl;

	// // powrot do Tury 2
	// world.readWorld("world.bin");
	// cout << world.toString() << endl;

	return 0;
}
