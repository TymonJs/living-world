#include <iostream>
#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Grass.h"
#include "Sheep.h"
#include "Dandelion.h"
#include "Wolf.h"
#include "Toadstool.h"
#include <vector>
#include <iostream>
#include <fstream> 

using namespace std;

int main()
{	
	// World test
	World world;

	Position posW2{ 3, 3 };
	Sheep sheep1{posW2};
	Position posW3{ 2, 3 };
	Sheep sheep2{posW3};

	Position postemp{0,0};
	Grass grass{postemp};

	Position posD{5,5};
	Dandelion dandelion{posD};

	Position posW{5,0};
	Wolf wolf{posW};

	Position posT{4,0};
	Toadstool t1{posT};

	// world.addOrganism(&sheep1);
	// world.addOrganism(&sheep2);
	// world.addOrganism(&grass);
	// world.addOrganism(&dandelion);
	world.addOrganism(&wolf);
	world.addOrganism(&t1);

	// Sheep sheep{Position{0,0},0};
	// Grass grass1{Position{0,1},0};
	// Grass grass2{Position{1,0},0};

	// world.addOrganism(&sheep);
	// world.addOrganism(&grass1);
	// world.addOrganism(&grass2);

	cout << world.toString() << endl;
	string hold;
	for(int i = 0; i < 100; i++){
		cin>> hold;
		world.makeTurn();
		cout << world.toString() << endl;
	}

	// // Tura 0
	// cout << world.toString() << endl;

	// // Tura 1
	// world.makeTurn();
	// cout << world.toString() << endl;

	// // Tura 2
	// world.makeTurn();
	// cout << world.toString() << endl;

	// // world.writeWorld("world.bin");

	// // Tura 3
	// world.makeTurn();
	// cout << world.toString() << endl;

	// // powrot do Tury 2
	// world.readWorld("world.bin");
	// cout << world.toString() << endl;

	return 0;
}
