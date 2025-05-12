#include "Sheep.h"
#include <set>

Sheep::Sheep() : Animal()
{
    species = "S";
}

Sheep::Sheep(Position pos)
    : Animal(3,pos,0,3,6,10)
{
    species = "S";
}

Sheep::Sheep(Position pos, int birth, std::vector<Lifespan> ancestorLifespans)
    : Animal(3,pos,birth,3,6,10,ancestorLifespans)
{
    species = "S";
}

bool Sheep::interactsWith(string species)
{
    std::set<std::string> interactables = {"G","D","T"};
    return interactables.count(species) ? true : false;
}

Organism* Sheep::breed(Position p, int birth, std::vector<Lifespan> l){
    return new Sheep{p,birth, l};
}