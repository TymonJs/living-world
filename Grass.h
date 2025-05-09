#pragma once
#include "Organism.h"
#include "Position.h"
#include "Plant.h"

using namespace std;

class Grass : public Plant
{
    public:
        Grass();
        Grass(Position position, int birth);
        Organism* breed(Position pos, int birth) override;
};