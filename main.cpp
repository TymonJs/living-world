#include <SDL2/SDL.h>
#include "World.h"
#include "Grass.h"
#include "Sheep.h"
#include "Dandelion.h"
#include "Wolf.h"
#include "Toadstool.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int CELL_SIZE = 40;

void renderWorld(SDL_Renderer* renderer, const World& world) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    auto organisms = world.getOrganisms();

    for (const auto& org : organisms) {
        Position pos = org->getPosition();
        std::string species = org->getSpecies();
        SDL_Rect rect = { pos.getX() * CELL_SIZE, pos.getY() * CELL_SIZE, CELL_SIZE, CELL_SIZE };

        if (species == "G") SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);       // Green
        else if (species == "S") SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White
        else if (species == "D") SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);   // Yellow
        else if (species == "W") SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // Gray
        else if (species == "T") SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);     // Red


        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
}

int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Living World",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    World world(16, 12);
    
    Position posS1{ 15, 1 };
	Position posS2{ 15, 0 };
	Position posG{0,0};
	Position posD{15,11};
	Position posW{0, 11};
	Position posT{8,6};

	world.addOrganism(make_shared<Sheep>(posS1));
    world.addOrganism(make_shared<Sheep>(posS2));
    world.addOrganism(make_shared<Grass>(posG));
    world.addOrganism(make_shared<Dandelion>(posD));
    world.addOrganism(make_shared<Wolf>(posW));
    world.addOrganism(make_shared<Toadstool>(posT));


    bool running = true;
    SDL_Event event;
    while (running) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE)
                    world.makeTurn();
            }
        }

        renderWorld(renderer, world);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
