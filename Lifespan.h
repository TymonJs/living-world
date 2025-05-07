#pragma once

using namespace std;

class Lifespan{

    private:
        int birth;
        int death;
        
    public:
        Lifespan(int birth);
        int getBirth();
        void setBirth(int round);
        int getDeath();
        void setDeath(int round);
};