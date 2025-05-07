#include "Plant.h"
#include "Organism.h"

Plant::Plant() : Organism()
{
	setSpecies("P");
}

Plant::Plant(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength)
	: Organism(power, position, birth, initiative, powerToReproduce, liveLength)
{
	setSpecies("P");
}


