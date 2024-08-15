// F3D_draw : Implementation of test functions for draw

#include "F3D_objects.h"

int prepareScene(F3D_Engine engine) {
    return (SDL_SetRenderDrawColor(engine.renderer, 96, 128, 255, 255) || SDL_RenderClear(engine.renderer));
}

void presentScene(F3D_Engine engine) {
    SDL_RenderPresent(engine.renderer);
}