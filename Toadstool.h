#pragma once
#include "Plant.h"

class Toadstool : public Plant{
    public:
        Toadstool();
        Toadstool(Position pos);
        Toadstool(Position pos, int birth, vector<shared_ptr<Lifespan>> l);
        shared_ptr<Organism> breed(Position pos, int birth, vector<shared_ptr<Lifespan>> l) override;
};