#include "Grass.h"
#include "Plant.h"

Grass::Grass(): Plant()
{
    setSpecies("G");
}
Grass::Grass(Position position)
    : Plant(0,position,0,0,3,6)
{
    setSpecies("G");
}
Grass::Grass(Position position, int birth, std::vector<shared_ptr<Lifespan>> ancestorLifespans)
    : Plant(0,position,birth,0,3,6,ancestorLifespans)
{
    setSpecies("G");
}
shared_ptr<Organism> Grass::breed(Position pos, int birth, std::vector<shared_ptr<Lifespan>> l){
    return make_shared<Grass>(pos,birth,l);
}