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

    for (const Organism* org : organisms) {
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

        Organism* org = nullptr;
        if (speciesChar == 'G') {
            org = new Grass();
        } else if (speciesChar == 'S') {
            org = new Sheep();
        } else if (speciesChar == 'D') {
            org = new Dandelion();
        } else if (speciesChar == 'W') {
            org = new Wolf();
        } else if (speciesChar == 'T') {
            org = new Toadstool();
        }

        if (org) {
            org->load(in);
            world.addOrganism(org);
        }
    }
}
