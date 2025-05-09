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
Organism* Dandelion::breed(Position pos, int birth){
    return new Dandelion{pos,birth};
}