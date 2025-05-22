#include "PositionSerialization.h"

void PositionSerialization::save(const Position& pos, std::ostream& out) {
    int x = pos.getX();
    int y = pos.getY();
    out.write(reinterpret_cast<const char*>(&x), sizeof(x));
    out.write(reinterpret_cast<const char*>(&y), sizeof(y));
}

void PositionSerialization::load(Position& pos, std::istream& in) {
    int x, y;
    in.read(reinterpret_cast<char*>(&x), sizeof(x));
    in.read(reinterpret_cast<char*>(&y), sizeof(y));
    pos.setX(x);
    pos.setY(y);
}
