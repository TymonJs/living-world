#include "Animal.h"

Animal::Animal(int power, Position position, int birth,int initiative, int powerToReproduce, int liveLength)
	: Organism(power, position,birth, initiative, powerToReproduce, liveLength)
{
	lastPosition = position;
	setSpecies("A");
}

Animal::Animal() : Organism()
{
	setSpecies("A");
	lastPosition = position;
}

void Animal::move(Position position){
	lastPosition = position;
	this->position = position;
	
}

