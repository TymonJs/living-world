#include "Dandelion.h"

Dandelion::Dandelion() : Plant()
{
    setSpecies("D");
}
Dandelion::Dandelion(Position pos)
    : Plant(0,pos,0,0,2,6)
{
    setSpecies("D");
}
Dandelion::Dandelion(Position pos, int birth,std::vector<shared_ptr<Lifespan>> ancestorLifespans)
    : Plant(0,pos,birth,0,2,6,ancestorLifespans)
{
    setSpecies("D");
}
shared_ptr<Organism> Dandelion::breed(Position pos, int birth,std::vector<shared_ptr<Lifespan>> ancestorLifespans){
    return make_shared<Dandelion>(pos,birth, ancestorLifespans);
}