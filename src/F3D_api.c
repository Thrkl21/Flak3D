// F3D_api.c : Implementation of API functions

#include "F3D_defs.h"
#include "F3D_api.h"

int F3D_init(F3D_Engine* engine) {
    // SDL Initialization
    F3D_SDL_CHECK_ZERO(SDL_Init(SDL_INIT_VIDEO ),"init");

    // Window creation
    engine->window = SDL_CreateWindow("Flak3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    F3D_SDL_CHECK_PTR(engine->window, engine->window, "createWindow");

    F3D_SDL_CHECK_TRUE(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"),"setHint"); // SDL scale quality

    // Renderer creation
    engine->renderer = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_ACCELERATED);
    F3D_SDL_CHECK_PTR(engine->renderer, engine->renderer, "createRenderer");

    return 0;
}

int F3D_setDrawColor(F3D_Engine engine, int r, int g, int b, int a) {
    F3D_SDL_CHECK_ZERO(SDL_SetRenderDrawColor(engine.renderer, r, g, b, a),"setDrawColor");
    return 0;
}

int F3D_clearScene(F3D_Engine engine) {
    // Set renderer background draw color
    F3D_setDrawColor(engine, 0, 0, 0, 255);
    // Draw background
    F3D_SDL_CHECK_ZERO(SDL_RenderClear(engine.renderer),"prepareScene");
    return 0;
}

void F3D_displayScene(F3D_Engine engine) {
    SDL_RenderPresent(engine.renderer);
}

int F3D_drawLine(F3D_Engine engine, int x1, int y1, int x2, int y2) {
    F3D_SDL_CHECK_ZERO(SDL_RenderDrawLine(engine.renderer, x1, y1, x2, y2),"drawLine");
    return 0;
}

int F3D_doInput(void) {
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

int F3D_Delay(Uint32 ms) {
    SDL_Delay(ms);
    return 0;
}

void F3D_quit(F3D_Engine engine) {
    if (engine.renderer) {
        SDL_DestroyRenderer(engine.renderer);
        engine.renderer = NULL;
    }
    if (engine.window) {
        SDL_DestroyWindow(engine.window);
        engine.window = NULL;
    }
    SDL_Quit();
}

