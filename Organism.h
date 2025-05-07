#pragma once
#include <string>
#include "Position.h"
#include <vector>
#include "Lifespan.h"

using namespace std;

class Organism
{
protected:
	int power;
	Position position;
	string species;
	Lifespan lifespan;
	vector<Lifespan> ancestorLifespans;
	int initiative;
	int powerToReproduce;
	int liveLength;
	
public:
	Organism();
	Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength);
	Organism(const Organism &o) 
        : power(o.power), 
          position(o.position), 
          species(o.species), 
          lifespan(o.lifespan), 
          ancestorLifespans(o.ancestorLifespans),
		  initiative(o.initiative),
		  powerToReproduce(o.powerToReproduce),
		  liveLength(o.liveLength)
    {}

    Organism(Organism &&o) noexcept 
        : power(o.power), 
          position(o.position), 
          species(std::move(o.species)), 
          lifespan(std::move(o.lifespan)), 
          ancestorLifespans(std::move(o.ancestorLifespans)),
          initiative(o.initiative),
          powerToReproduce(o.powerToReproduce),
          liveLength(o.liveLength)
    {
        o.power = 0;
        o.initiative = 0;
        o.powerToReproduce = 0;
        o.liveLength = 0;
    }

	Organism& operator=(const Organism&) = default;
	Organism& operator=(Organism&&) = default;
	~Organism() = default;

	int getPower();
	void setPower(int power);
	Position getPosition();
	void setPosition(Position position);
	string getSpecies();
	void setSpecies(string spec);
	vector<Lifespan> getAncestorLifespans();

	string toString();

};