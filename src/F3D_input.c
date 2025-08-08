// F3D_input.c : Implementation of input handling functions

#include <SDL.h>

int doInput(void) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return 1; // Exit event

            default:
                break;
        }
    }
    return 0; // Nominal return
}