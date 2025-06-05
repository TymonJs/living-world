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

Sheep::Sheep(Position pos, int birth, std::vector<shared_ptr<Lifespan>> ancestorLifespans)
    : Animal(3,pos,birth,3,6,10,ancestorLifespans)
{
    species = "S";
}

shared_ptr<Organism> Sheep::breed(Position p, int birth, std::vector<shared_ptr<Lifespan>> l){
    return make_shared<Sheep>(p,birth, l);
}