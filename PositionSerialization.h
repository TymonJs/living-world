#pragma once
#include <iostream>
#include "Position.h"

class PositionSerialization {
public:
    static void save(const Position& pos, std::ostream& out);
    static void load(Position& pos, std::istream& in);
};
