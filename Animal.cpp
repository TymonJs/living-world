#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal() : Organism()
{
	setSpecies("A");
	lastPosition = position;
}
Animal::Animal(int power, Position position, int birth,int initiative, int powerToReproduce, int liveLength)
	: Organism(power, position,birth, initiative, powerToReproduce, liveLength)
{
	lastPosition = position;
	setSpecies("A");
}
Animal::Animal(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength,std::vector<Lifespan> ancestorLifespans)
	: Organism(power, position, birth, initiative, powerToReproduce, liveLength,ancestorLifespans)
{
	setSpecies("A");
}

void Animal::move(Position position){

	// cout << "Sheep moving from (" << this->getPosition().getX()+1<< ", " << this->getPosition().getY() + 1 << ") to (" << position.getX() + 1 << ", " << position.getY() + 1 << ")" << endl;
	lastPosition = this->position;
	this->position = position;
}

