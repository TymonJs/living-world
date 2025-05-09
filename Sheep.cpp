#include "Sheep.h"
#include <set>

Sheep::Sheep() : Animal()
{
    species = "S";
}

Sheep::Sheep(Position pos, int birth)
    : Animal(3,pos,birth,3,6,10)
{
    species = "S";
}

bool Sheep::interactsWith(string species)
{
    std::set<std::string> interactables = {"G"};
    return interactables.count(species) ? true : false;
}

Organism* Sheep::breed(Position p, int birth){
    return new Sheep{p,birth};
}