// F3D_main.c : File for library testing

#include <SDL.h>
#include "F3D.h"

F3D_Engine engine;

int main() {
    engine = (F3D_Engine) {0}; // Setting all engine pointers to null pointers
    if (F3D_init(&engine) != 0) {
        fprintf(stderr, "Error during F3D engine initialization");
        return -1;
    }

    int F3D_loop;
    int F3D_stop;
    F3D_loop = 0;
    F3D_stop = 0;

    while(!F3D_stop){
        if (prepareScene(engine)) {
            const char* errorMsg;
            errorMsg = SDL_GetError();
            fprintf(stderr, "[ERROR] : SDL error : %s\n", errorMsg);
            return -1;
        }
        F3D_stop = doInput();
        presentScene(engine);
        SDL_Delay(16);
        printf("Game loop #%d\n", F3D_loop);
        F3D_loop += 1;
    }

    if (engine.renderer) {
        SDL_DestroyRenderer(engine.renderer);
        engine.renderer = NULL;
    }
    if (engine.window) {
        SDL_DestroyWindow(engine.window);
        engine.window = NULL;
    }
    SDL_Quit();
    return 0;
}
