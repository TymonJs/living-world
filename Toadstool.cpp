#include "Toadstool.h"

Toadstool::Toadstool() : Plant()
{
    setSpecies("T");
}
Toadstool::Toadstool(Position pos) 
    : Plant(0,pos,0, 0, 4, 12)
{
    setSpecies("T");
}
Toadstool::Toadstool(Position pos, int birth, std::vector<Lifespan> l)
    : Plant(0,pos,birth,0,4,12,l)
{
    setSpecies("T");
}
Organism* Toadstool::breed(Position pos, int birth,std::vector<Lifespan> ancestorLifespans){
    return new Toadstool{pos,birth, ancestorLifespans};
}