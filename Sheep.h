#pragma once
#include "Animal.h"

using namespace std;

class Sheep : public Animal{
public:
    Sheep();
    Sheep(Position position);
    Sheep(Position position, int birth, vector<Lifespan> ancestorLifespans);
    bool interactsWith(string species) override;
    Organism* breed(Position p, int birth, vector<Lifespan> l) override;
};