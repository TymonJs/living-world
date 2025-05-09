#pragma once
#include "Animal.h"

class Wolf : public Animal{
    public:
        Wolf();
        Wolf(Position pos, int birth);
        bool interactsWith(string species) override;
        Organism* breed(Position p, int birth) override;
};