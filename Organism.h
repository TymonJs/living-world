#pragma once
#include "Position.h"
#include <string>
#include <vector>
#include <memory>
#include "Lifespan.h"
#include <iostream>

using namespace std;

class Organism
{
protected:
	int power;
	Position position;
	string species;
	shared_ptr<Lifespan> lifespan;
	vector<shared_ptr<Lifespan>> ancestorLifespans;
	int initiative;
	int powerToReproduce;
	int liveLength;
	bool predator;
	bool poisonous;
	
public:
	Organism();
	Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength);
	Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength, vector<shared_ptr<Lifespan>> ancestorLifespans);
	Organism(const Organism &o) 
        : power(o.power), 
          position(o.position), 
          species(o.species), 
          lifespan(o.lifespan), 
          ancestorLifespans(o.ancestorLifespans),
		  initiative(o.initiative),
		  powerToReproduce(o.powerToReproduce),
		  liveLength(o.liveLength),
		  predator(o.predator),
		  poisonous(o.poisonous) {}

    Organism(Organism &&o) noexcept 
        : power(o.power), 
          position(o.position), 
          species(std::move(o.species)), 
          lifespan(std::move(o.lifespan)), 
          ancestorLifespans(std::move(o.ancestorLifespans)),
          initiative(o.initiative),
          powerToReproduce(o.powerToReproduce),
          liveLength(o.liveLength),
		  predator(o.predator),
		  poisonous(o.poisonous)
    {
        o.power = 0;
        o.initiative = 0;
        o.powerToReproduce = 0;
        o.liveLength = 0;
    }

	Organism& operator=(const Organism&) = default;
	Organism& operator=(Organism&&) = default;
	virtual ~Organism();

	int getPower();
	void setPower(int power);

	Position getPosition();
	void setPosition(Position position);

	string getSpecies() const;
	void setSpecies(string spec);

	int getInitiative();

	int getLiveLength();
	void setLiveLength(int l);
	
	vector<shared_ptr<Lifespan>> getAncestorLifespans();
	void addAncestorLifespan(shared_ptr<Lifespan> s);
	shared_ptr<Lifespan> getLifespan();

	void consequences(Organism* other);
	bool isDead();
	void die(int turn);

	string toString();

	virtual void move(Position position) = 0;
	virtual shared_ptr<Organism> breed(Position pos, int birth, vector<shared_ptr<Lifespan>> l) = 0;
	
	bool interactsWith(Organism* other);
	bool canReproduce();

	bool isPoisonous();
	void setPoisonous(bool b);

	bool isPredator();
	void setPredator(bool b);

	virtual void save(ostream& out) const;
    virtual void load(istream& in);        

};