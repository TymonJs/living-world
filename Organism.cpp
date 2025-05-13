#include "Organism.h"
#include <vector>
#include "Lifespan.h"

Organism::Organism()
	: power(0),
	position(0, 0), 
	species("O"), 
	lifespan(new Lifespan(0)),
	ancestorLifespans({}),
	initiative(0),
	powerToReproduce(0),
	liveLength(0) {}

Organism::Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength)
    : power(power), 
	position(position), 
	species("O"), 
	lifespan(new Lifespan(birth)), 
	ancestorLifespans({}),
	initiative(initiative),
	powerToReproduce(powerToReproduce),
	liveLength(liveLength) {}

Organism::Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength, std::vector<Lifespan*> ancestorLifespans)
	: power(power), 
	position(position), 
	species("O"), 
	lifespan(new Lifespan(birth)), 
	ancestorLifespans(ancestorLifespans),
	initiative(initiative),
	powerToReproduce(powerToReproduce),
	liveLength(liveLength) {}

Organism::~Organism() {}

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

std::vector<Lifespan*> Organism::getAncestorLifespans()
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
int Organism::getInitiative()
{
	return this->initiative;
}
int Organism::getLiveLength()
{
	return this->liveLength;
}
void Organism::setLiveLength(int l){
	this->liveLength=l;
}
Lifespan* Organism::getLifespan(){
	return this->lifespan;
}
void Organism::addAncestorLifespan(Lifespan* l){
	this->ancestorLifespans.push_back(l);
}
void Organism::consequences(Organism* other){
	if (other->getSpecies() == "T" || power < other->getPower()){
		this->setLiveLength(0);
	}
	else{
		other->setLiveLength(0);
	}
	
}
bool Organism::isDead(){
	return this->liveLength<=0;
}
bool Organism::canReproduce(){
	return power>=powerToReproduce;
}
void Organism::die(int turn){
	this->lifespan->setDeath(turn);
}

void Organism::save(std::ostream& out) const {
    position.save(out);
    out.write(reinterpret_cast<const char*>(&power), sizeof(power));
    out.write(reinterpret_cast<const char*>(&initiative), sizeof(initiative));
    out.write(reinterpret_cast<const char*>(&powerToReproduce), sizeof(powerToReproduce));
    out.write(reinterpret_cast<const char*>(&liveLength), sizeof(liveLength));
    out.write(reinterpret_cast<const char*>(&species[0]), species.size() + 1);

    lifespan->save(out);
    
    size_t ancestorCount = ancestorLifespans.size();
    out.write(reinterpret_cast<const char*>(&ancestorCount), sizeof(ancestorCount));
    for (const auto& ancestor : ancestorLifespans) {
        ancestor->save(out);
    }
}

void Organism::load(std::istream& in) {
    position.load(in);
    in.read(reinterpret_cast<char*>(&power), sizeof(power));
    in.read(reinterpret_cast<char*>(&initiative), sizeof(initiative));
    in.read(reinterpret_cast<char*>(&powerToReproduce), sizeof(powerToReproduce));
    in.read(reinterpret_cast<char*>(&liveLength), sizeof(liveLength));

    char speciesBuffer[100];
    in.getline(speciesBuffer, sizeof(speciesBuffer));
    species = speciesBuffer;

    lifespan->load(in);
    
    size_t ancestorCount;
    in.read(reinterpret_cast<char*>(&ancestorCount), sizeof(ancestorCount));
    ancestorLifespans.clear();
    for (size_t i = 0; i < ancestorCount; ++i) {
        Lifespan* ancestor = new Lifespan(0);
        ancestor->load(in);
        ancestorLifespans.push_back(ancestor);
    }
}