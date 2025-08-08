// F3D_draw : Implementation of test functions for draw

#include "F3D_objects.h"

int prepareScene(F3D_Engine engine) {
    // Set renderer background draw color
    if (SDL_SetRenderDrawColor(engine.renderer, 0, 0, 0, 255)) {
        fprintf(stderr, "Error setting the render draw color : %s\n", SDL_GetError());
        return -1;
    }

    // Draw background
    if (SDL_RenderClear(engine.renderer)) {
        fprintf(stderr, "Error clearing the renderer : %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void presentScene(F3D_Engine engine) {
    SDL_RenderPresent(engine.renderer);
}