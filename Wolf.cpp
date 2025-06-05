#include "Wolf.h"
#include <set>

Wolf::Wolf() : Animal()
{
    setSpecies("W");
    setPredator(true);
}
Wolf::Wolf(Position pos)
    : Animal(8,pos,0,5,16,20)
{
    setSpecies("W");
    setPredator(true);
}
Wolf::Wolf(Position pos, int birth, std::vector<shared_ptr<Lifespan>> ancestorLifespans)
    : Animal(8,pos,birth,5,16,20,ancestorLifespans)
{
    setSpecies("W");
    setPredator(true);
}

shared_ptr<Organism> Wolf::breed(Position p, int birth, std::vector<shared_ptr<Lifespan>> l){
    return make_shared<Wolf>(p,birth, l);
}