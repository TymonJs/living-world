#include "Lifespan.h"

Lifespan::Lifespan(int birth): birth(birth), death(-1){}

int Lifespan::getBirth(){
    return this->birth; 
}
void Lifespan::setBirth(int round){
    this->birth = round;
}
int Lifespan::getDeath(){
    return this->death;
}
void Lifespan::setDeath(int round){
    this->death = round;
}
void Lifespan::save(std::ostream& out) const {
    out.write(reinterpret_cast<const char*>(&birth), sizeof(birth));
    out.write(reinterpret_cast<const char*>(&death), sizeof(death));
}

void Lifespan::load(std::istream& in) {
    in.read(reinterpret_cast<char*>(&birth), sizeof(birth));
    in.read(reinterpret_cast<char*>(&death), sizeof(death));
}