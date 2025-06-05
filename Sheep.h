#pragma once
#include "Animal.h"

using namespace std;

class Sheep : public Animal{
public:
    Sheep();
    Sheep(Position position);
    Sheep(Position position, int birth, vector<shared_ptr<Lifespan>> ancestorLifespans);
    shared_ptr<Organism> breed(Position p, int birth, vector<shared_ptr<Lifespan>> l) override;
};