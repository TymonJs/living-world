#include "World.h"
#include <fstream>
#include <algorithm>
#include <iostream>

string World::getOrganismFromPosition(int x, int y)
{
	for (Organism* org : organisms)
		if (org->getPosition().getX() == x && org->getPosition().getY() == y)
			return org->getSpecies();
	return "";
}

Organism* World::getOrganismPointerFromPosition(Position p)
{
    auto it = std::find_if(organisms.begin(), organisms.end(),
        [&](Organism* org){
            Position currPos = org->getPosition();
            return currPos.getX() == p.getX() && currPos.getY() == p.getY();
        });

    if (it != organisms.end()) return *it;

    return nullptr;
}


bool World::isPositionOnWorld(int x, int y)
{
	return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
}

bool World::isPositionFree(Position position) {
	return this->getOrganismFromPosition(position.getX(), position.getY()).empty();
}
bool World::isPositionFree(int x, int y) {
	return this->getOrganismFromPosition(x, y).empty();
}


vector<Position> World::getVectorOfFreePositionsAround(Position position)
{	
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for(int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y){
			if (x == 0 && y == 0) continue;
			int new_x = pos_x + x, new_y = pos_y + y;
			if (isPositionOnWorld(new_x, new_y) && isPositionFree(new_x, new_y)){
				result.push_back(Position(pos_x + x, pos_y + y));
			}
		}

	return result;
}

vector<Position> World::getVectorOfInteractablePositionsAroundOrganism(Organism* org)
{
	Position position = org->getPosition();
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;

	for(int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y){
			if (x == 0 && y == 0) continue;
			int new_x = pos_x + x, new_y = pos_y + y;
			if (!isPositionOnWorld(new_x,new_y)) continue;

			if (isPositionFree(new_x, new_y) || org->interactsWith(getOrganismFromPosition(new_x,new_y))){
				result.push_back(Position(new_x, new_y));
			}
		}

	return result;
}

World::World(int worldX, int worldY)
{
	setWorldX(worldX);
	setWorldY(worldY);
}

int World::getWorldX()
{
	return this->worldX;
}

void World::setWorldX(int worldX)
{
	this->worldX = worldX;
}

int World::getWorldY()
{
	return this->worldY;
}

void World::setWorldY(int worldY)
{
	this->worldY = worldY;
}

int World::getTurn()
{
	return this->turn;
}

void World::addOrganism(Organism* organism)
{
	Position pos = organism->getPosition();
	if (isPositionOnWorld(pos.getX(), pos.getY())) {
		this->organisms.push_back(organism);

		std::sort(organisms.begin(), organisms.end(),
			[](Organism* a, Organism* b) {
				return a->getInitiative() > b->getInitiative();
			});
	}
}
void World::makeTurn()
{
	vector<Position> freePositions;
	vector<Position> interactablePositions;
	int numberOfFreePositions;
	int numberOfInteractablePositions;
	int randomIndex;

	vector<Organism*> curr = organisms;

	srand(time(0));
	for (Organism* org : curr) {
		if (org->isDead()) continue;

		freePositions = getVectorOfFreePositionsAround(org->getPosition());
		interactablePositions = getVectorOfInteractablePositionsAroundOrganism(org);
		numberOfFreePositions = freePositions.size();
		numberOfInteractablePositions = interactablePositions.size();
		
		// std::cout << org->getSpecies() <<" interactable positions: " << numberOfInteractablePositions << std::endl;
		
		if (numberOfFreePositions > 0 && org->canReproduce()){
			randomIndex = rand() % numberOfFreePositions;
			Position childPosition = freePositions[randomIndex];
			Organism* child = org->breed(childPosition,turn,org->getAncestorLifespans());

			addOrganism(child);
			org->setPower(org->getPower()/2);
		}
		else if (numberOfInteractablePositions > 0) {
			randomIndex = rand() % numberOfInteractablePositions;
			Position newPosition = interactablePositions[randomIndex];
			Organism* other = getOrganismPointerFromPosition(newPosition);
			if (other){
				org->consequences(other);
				if (other->isDead()){
					other -> die(turn);
					org -> addAncestorLifespan(other->getLifespan());
					org -> move(newPosition);
				}
				else if (org -> isDead()){
					org -> die(turn);
					other -> addAncestorLifespan(org->getLifespan());
				}
			}
			else org-> move(newPosition);

			}

		org->setPower(org->getPower()+1);
		org->setLiveLength(org->getLiveLength()-1);
	}

	organisms.erase(
		remove_if(organisms.begin(), organisms.end(),
			[](Organism* org) {
				return org->isDead();
			}),
		organisms.end()
	);
	
	turn++;
}

string World::toString()
{
	string result = "\nturn: " + to_string(getTurn()) + "\n";
	string spec;

	for (int wY = 0; wY < getWorldY(); ++wY) {
		for (int wX = 0; wX < getWorldX(); ++wX) {
			spec = getOrganismFromPosition(wX, wY);
			if (spec != "")
				result += spec;
			else
				result += separator;
		};
		result += "\n";
	}
	return result;
}

