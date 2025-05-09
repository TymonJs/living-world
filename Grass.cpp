#include "Grass.h"
#include "Plant.h"

Grass::Grass(): Plant()
{
    setSpecies("G");
}
Grass::Grass(Position position, int birth)
    : Plant(0,position,birth,0,3,6)
{
    setSpecies("G");
}
Grass::Grass(Position position, int birth, std::vector<Lifespan> ancestorLifespans)
    : Plant(0,position,birth,0,3,6,ancestorLifespans)
{
    setSpecies("G");
}
Organism* Grass::breed(Position pos, int birth, std::vector<Lifespan> l){
    return new Grass{pos,birth,l};
}