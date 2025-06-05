#include "Organism.h"
#include <vector>
#include "Lifespan.h"
#include "PositionSerialization.h"
#include <typeinfo>
#include "Animal.h"
#include "Plant.h"

Organism::Organism()
	: power(0),
	position(0, 0), 
	species("O"), 
	lifespan(make_shared<Lifespan>(0)),
	ancestorLifespans({}),
	initiative(0),
	powerToReproduce(0),
	liveLength(0),
	predator(false),
	poisonous(false) {}

Organism::Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength)
    : power(power), 
	position(position), 
	species("O"), 
	lifespan(make_shared<Lifespan>(birth)),
	ancestorLifespans({}),
	initiative(initiative),
	powerToReproduce(powerToReproduce),
	liveLength(liveLength),
	predator(false),
	poisonous(false) {}

Organism::Organism(int power, Position position, int birth, int initiative, int powerToReproduce, int liveLength, std::vector<shared_ptr<Lifespan>> ancestorLifespans)
	: power(power), 
	position(position), 
	species("O"), 
	lifespan(make_shared<Lifespan>(birth)),
	ancestorLifespans(ancestorLifespans),
	initiative(initiative),
	powerToReproduce(powerToReproduce),
	liveLength(liveLength),
	predator(false),
	poisonous(false) {}

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

std::vector<shared_ptr<Lifespan>> Organism::getAncestorLifespans()
{
	return this->ancestorLifespans;
}

string Organism::toString()
{
	return "{ species: " + this->getSpecies() + 
		", power: " + to_string(getPower()) + 
		", position: " + getPosition().toString() + "}";
}

string Organism::getSpecies() const
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
shared_ptr<Lifespan> Organism::getLifespan(){
	return this->lifespan;
}
void Organism::addAncestorLifespan(shared_ptr<Lifespan> l){
	this->ancestorLifespans.push_back(l);
}
void Organism::consequences(Organism* other){
	// przed SOLID: if (other->getSpecies() == "T"){
	if (other->isPoisonous()){
		this->setLiveLength(0);
		other->setLiveLength(0);
	}
	else if (power < other->getPower()){
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

void Organism::setPoisonous(bool b){
	this->poisonous=b;
}
bool Organism::isPoisonous(){
	return this->poisonous;
}
void Organism::setPredator(bool b){
	this->predator=b;
}
bool Organism::isPredator(){
	return this->predator;
}

void Organism::save(std::ostream& out) const {
	PositionSerialization::save(position,out);
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
    PositionSerialization::load(position,in);
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
        shared_ptr<Lifespan> ancestor = make_shared<Lifespan>(0);
        ancestor->load(in);
        ancestorLifespans.push_back(ancestor);
    }
}

bool Organism::interactsWith(Organism* other) {
    if (!other) {
        return false;
    }

    bool this_is_animal = (dynamic_cast<Animal*>(this) != nullptr);
    bool this_is_predator = this->isPredator();

    bool other_is_animal = (dynamic_cast<Animal*>(other) != nullptr);
    bool other_is_plant = (dynamic_cast<Plant*>(other) != nullptr);
    bool other_is_poisonous = other->isPoisonous(); 
	bool other_is_predator = other->isPredator();

    if (this_is_predator && ((other_is_animal && !other_is_predator) || (other_is_poisonous))) {
		return true;
    }

    if (this_is_animal && !this_is_predator && other_is_plant) {
		return true;
    }

    return false;
}