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