#pragma once
#include "Plant.h"

class Toadstool : public Plant{
    public:
        Toadstool();
        Toadstool(Position pos);
        Toadstool(Position pos, int birth, vector<Lifespan> l);
        Organism* breed(Position pos, int birth, vector<Lifespan> l) override;
};