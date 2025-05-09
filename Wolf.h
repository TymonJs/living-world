#pragma once
#include "Animal.h"

class Wolf : public Animal{
    public:
        Wolf();
        Wolf(Position pos);
        Wolf(Position position, int birth, vector<Lifespan> ancestorLifespans);
        bool interactsWith(string species) override;
        Organism* breed(Position p, int birth, vector<Lifespan> l) override;
};