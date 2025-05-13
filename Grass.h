#pragma once
#include "Organism.h"
#include "Position.h"
#include "Plant.h"

using namespace std;

class Grass : public Plant
{
    public:
        Grass();
        Grass(Position position);
        Grass(Position position, int birth, vector<Lifespan*> ancestorLifespans);
        Organism* breed(Position pos, int birth, vector<Lifespan*> l) override;
};