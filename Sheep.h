#pragma once
#include "Animal.h"

using namespace std;

class Sheep : public Animal{
public:
    Sheep();
    Sheep(Position position, int birth);
    bool interactsWith(string species) override;
    Organism* breed(Position p, int birth) override;
};