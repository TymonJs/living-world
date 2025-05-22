#pragma once

#include "World.h"
#include <iostream>

class WorldSerialization {
public:
    static void save(const World& world, std::ostream& out);
    static void load(World& world, std::istream& in);
};
