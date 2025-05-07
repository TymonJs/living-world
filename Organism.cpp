#include "Organism.h"
#include <vector>
#include "Lifespan.h"

Organism::Organism()
	: power(0),
	position(0, 0), 
	species("O"), 
	lifespan(0),
	ancestorLifespans({}),
	initiative(0),
	powerToReproduce(0),
	liveLength(0) {}

Organism::Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength)
    : power(power), 
	position(position), 
	species("O"), 
	lifespan(birth), 
	ancestorLifespans({}),
	initiative(initiative),
	powerToReproduce(powerToReproduce),
	liveLength(liveLength) {}


int Organism::getPower()
{
	return this->power;
}

void Organism::setPower(int power)
{
	this->power = power;
}

Position Organism::getPosition()
{
	return this->position;
}

void Organism::setPosition(Position position)
{
	this->position = position;
}

std::vector<Lifespan> Organism::getAncestorLifespans()
{
	return this->ancestorLifespans;
}

string Organism::toString()
{
	return "{ species: " + this->getSpecies() + 
		", power: " + to_string(getPower()) + 
		", position: " + getPosition().toString() + "}";
}

string Organism::getSpecies()
{
	return this->species;
}

void Organism::setSpecies(string spec)
{
	this->species = spec;
}
