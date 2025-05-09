#pragma once
#include "Plant.h"

class Dandelion : public Plant{
    public:
        Dandelion();
        Dandelion(Position position, int birth);
        Organism* breed(Position pos, int birth) override;
};