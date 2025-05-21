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

    for (auto* org : organisms) {
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

    World world(16, 12); // worldX = 16, worldY = 12
    
    Position posW2{ 3, 3 };
	Position posW3{ 2, 3 };
	Position postemp{0,0};
	Position posD{5,5};
	Position posW{5,0};
	Position posT{4,0};

	world.addOrganism(new Sheep(posW2));
    world.addOrganism(new Sheep(posW3));
    world.addOrganism(new Grass(postemp));
    world.addOrganism(new Dandelion(posD));
    world.addOrganism(new Wolf(posW));
    world.addOrganism(new Toadstool(posT));


    bool running = true;
    SDL_Event event;
    while (running) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE)
                    world.makeTurn(); // advance the simulation on SPACE
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
