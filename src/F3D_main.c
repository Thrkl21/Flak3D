// F3D_main.c : File for library testing

#include <SDL.h>
#include "F3D.h"

F3D_Engine engine;

int main() {
    memset(&engine, 0, sizeof(engine));
    if (F3D_init(engine) != 0) {
        fprintf(stderr, "Error during F3D engine initialization");
        return 1;
    }

    int F3D_loop;
    int prepareSceneResult;
    F3D_loop = 0;
    prepareSceneResult = 0;

    while(1){
        prepareSceneResult = prepareScene(engine);
        // TODO: DEBUG to remove
        if (prepareSceneResult) {
            const char* errorMsg;
            errorMsg = SDL_GetError();
            fprintf(stderr, "[ERROR] : SDL error : %s\n", errorMsg);
            return 1;
        }
        doInput();
        presentScene(engine);
        SDL_Delay(16);
        printf("Game loop #%d : prepareSceneResult = %d\n", F3D_loop, prepareSceneResult);
        F3D_loop += 1;
    }

    SDL_DestroyWindow(engine.window);
    SDL_Quit();
    return 0;
}
