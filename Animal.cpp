#include "Animal.h"
#include <iostream>
using namespace std;
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

	cout << "Sheep moving from (" << this->getPosition().getX()+1<< ", " << this->getPosition().getY() + 1 << ") to (" << position.getX() + 1 << ", " << position.getY() + 1 << ")" << endl;
	lastPosition = this->position;
	this->position = position;
}

