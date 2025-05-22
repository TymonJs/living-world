#pragma once

#include <vector>
#include <ctime>
#include "Organism.h"
#include <iostream>
#include <fstream>

using namespace std;

class World
{
private:
	int worldX;
	int worldY;
	int turn = 0;
	vector<Organism*> organisms;
	char separator = '.';

	string getOrganismFromPosition(int x, int y);
	Organism* getOrganismPointerFromPosition(Position p);
	bool isPositionOnWorld(int x, int y);
	bool isPositionFree(Position position);
	bool isPositionFree(int x, int y);

public:
	World(int worldX, int worldY);
	World() : World(6, 6) {};

	int getWorldX() const;
	void setWorldX(int worldX);
	int getWorldY() const;
	void setWorldY(int worldY);

	int getTurn() const;
	
	vector<Organism*> getOrganisms() const;
	void addOrganism(Organism* organism);
	void removeOrganism(Organism* organism);
	vector<Position> getVectorOfFreePositionsAround(Position position);
	vector<Position> getVectorOfInteractablePositionsAroundOrganism(Organism* org);
	void makeTurn();
	void setTurn(int turn);

	string toString();

};

