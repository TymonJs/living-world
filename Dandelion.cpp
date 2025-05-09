#include "Dandelion.h"

Dandelion::Dandelion() : Plant()
{
    setSpecies("D");
}
Dandelion::Dandelion(Position pos, int birth)
    : Plant(0,pos,birth,0,2,6)
{
    setSpecies("D");
}
Dandelion::Dandelion(Position pos, int birth,std::vector<Lifespan> ancestorLifespans)
    : Plant(0,pos,birth,0,2,6,ancestorLifespans)
{
    setSpecies("D");
}
Organism* Dandelion::breed(Position pos, int birth,std::vector<Lifespan> ancestorLifespans){
    return new Dandelion{pos,birth, ancestorLifespans};
}