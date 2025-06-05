#pragma once
#include "Animal.h"

class Wolf : public Animal{
    public:
        Wolf();
        Wolf(Position pos);
        Wolf(Position position, int birth, vector<shared_ptr<Lifespan>> ancestorLifespans);
        shared_ptr<Organism> breed(Position p, int birth, vector<shared_ptr<Lifespan>> l) override;
};