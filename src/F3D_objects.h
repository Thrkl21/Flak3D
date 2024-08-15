// F3D_objects.h : Objects prototypes

#ifndef F3D_OBJECTS
#define F3D_OBJECTS

#include <SDL.h>

typedef struct F3D_Engine_s {
    SDL_Window* window;
    SDL_Renderer* renderer;
} F3D_Engine;

#endif