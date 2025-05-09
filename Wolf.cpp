#include "Wolf.h"
#include <set>

Wolf::Wolf() : Animal()
{
    setSpecies("W");
}
Wolf::Wolf(Position pos)
    : Animal(8,pos,0,5,16,20)
{
    setSpecies("W");
}
Wolf::Wolf(Position pos, int birth, std::vector<Lifespan> ancestorLifespans)
    : Animal(8,pos,birth,5,16,20,ancestorLifespans)
{
    setSpecies("W");
}
bool Wolf::interactsWith(string species)
{
    std::set<std::string> interactables = {"S"};
    return interactables.count(species) ? true : false;
}

Organism* Wolf::breed(Position p, int birth, std::vector<Lifespan> l){
    return new Wolf{p,birth, l};
}