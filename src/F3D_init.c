// F3D_init.c : Implementation of the initialization functions

#include "F3D_defs.h"
#include "F3D_objects.h"

int F3D_init(F3D_Engine engine) {
    // SDL Initialization
    if (SDL_Init(SDL_INIT_VIDEO ) != 0) {
        fprintf(stderr, "Error during SDL initialization : %s\n", SDL_GetError());
        return 1;
    }

    // Window creation
    engine.window = SDL_CreateWindow("Flak3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (engine.window == NULL) {
        fprintf(stderr, "Error creating the Flak3D engine window : %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    // Renderer creation
    engine.renderer = SDL_CreateRenderer(engine.window, -1, SDL_RENDERER_SOFTWARE);
    if (engine.renderer == NULL) {
        fprintf(stderr, "Error creating the Flak3D engine renderer: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}