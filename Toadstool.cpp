#include "Toadstool.h"

Toadstool::Toadstool() : Plant()
{
    setSpecies("T");
    setPoisonous(true);
}
Toadstool::Toadstool(Position pos) 
    : Plant(0,pos,0, 0, 4, 12)
{
    setSpecies("T");
    setPoisonous(true);
}
Toadstool::Toadstool(Position pos, int birth, std::vector<shared_ptr<Lifespan>> l)
    : Plant(0,pos,birth,0,4,12,l)
{
    setSpecies("T");
    setPoisonous(true);
}
shared_ptr<Organism> Toadstool::breed(Position pos, int birth,std::vector<shared_ptr<Lifespan>> ancestorLifespans){
    return make_shared<Toadstool>(pos,birth, ancestorLifespans);
}