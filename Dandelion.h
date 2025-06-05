#pragma once
#include "Plant.h"

class Dandelion : public Plant{
    public:
        Dandelion();
        Dandelion(Position position);
        Dandelion(Position position, int birth, vector<shared_ptr<Lifespan>> ancestorLifespans);
        shared_ptr<Organism> breed(Position pos, int birth, vector<shared_ptr<Lifespan>> l) override;
};