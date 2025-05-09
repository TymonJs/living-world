#pragma once
#include "Plant.h"

class Dandelion : public Plant{
    public:
        Dandelion();
        Dandelion(Position position);
        Dandelion(Position position, int birth, vector<Lifespan> ancestorLifespans);
        Organism* breed(Position pos, int birth, vector<Lifespan> l) override;
};