#include "WorldSerialization.h"
#include "Grass.h"
#include "Sheep.h"
#include "Dandelion.h"
#include "Wolf.h"
#include "Toadstool.h"

void WorldSerialization::save(const World& world, std::ostream& out){
    int worldX = world.getWorldX();
    int worldY = world.getWorldY();
    int turn = world.getTurn();

    out.write(reinterpret_cast<const char*>(&worldX), sizeof(worldX));
    out.write(reinterpret_cast<const char*>(&worldY), sizeof(worldY));
    out.write(reinterpret_cast<const char*>(&turn), sizeof(turn));

    const auto& organisms = world.getOrganisms();
    size_t organismCount = organisms.size();
    out.write(reinterpret_cast<const char*>(&organismCount), sizeof(organismCount));

    for (const shared_ptr<Organism>& org : organisms) {
        out.put(org->getSpecies()[0]); 
        org->save(out);
    }
}

void WorldSerialization::load(World& world, std::istream& in) {
    int worldX, worldY, turn;

    in.read(reinterpret_cast<char*>(&worldX), sizeof(worldX));
    in.read(reinterpret_cast<char*>(&worldY), sizeof(worldY));
    in.read(reinterpret_cast<char*>(&turn), sizeof(turn));

    world.setWorldX(worldX);
    world.setWorldY(worldY);

    world.setTurn(turn);

    size_t organismCount;
    in.read(reinterpret_cast<char*>(&organismCount), sizeof(organismCount));

    for (size_t i = 0; i < organismCount; ++i) {
        char speciesChar;
        in.get(speciesChar);

        shared_ptr<Organism> org;
        if (speciesChar == 'G') {
            org = make_shared<Grass>();
        } else if (speciesChar == 'S') {
            org = make_shared<Sheep>();
        } else if (speciesChar == 'D') {
            org = make_shared<Dandelion>();
        } else if (speciesChar == 'W') {
            org = make_shared<Wolf>();
        } else if (speciesChar == 'T') {
            org = make_shared<Toadstool>();
        }

        if (org) {
            org->load(in);
            world.addOrganism(org);
        }
    }
}
