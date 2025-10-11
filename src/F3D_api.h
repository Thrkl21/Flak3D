// F3D_api.h : Definition of API functions

#include "F3D_defs.h"

#include <SDL.h>

#define F3D_SDL_FAIL(op) \
    do { \
        const char* _err = SDL_GetError(); \
        fprintf(stderr, "[F3D][%s] SDL failure on %s: %s\n", __func__, (op), _err && *_err ? _err : "(no message)"); \
    } while (0)

#define F3D_SDL_CHECK_ZERO(expr, opDesc) \
    do { \
        if ((expr) != 0) { F3D_SDL_FAIL(opDesc); return -1; } \
    } while (0)

#define F3D_SDL_CHECK_TRUE(expr, opDesc) \
    do { \
        if (!(expr)) { F3D_SDL_FAIL(opDesc); return -1; } \
    } while (0) \

#define F3D_SDL_CHECK_PTR(assign_lhs, expr, opDesc) \
    do { \
        (assign_lhs) = (expr); \
        if (!(assign_lhs)) { F3D_SDL_FAIL(opDesc); return -1; } \
    } while (0)

typedef struct F3D_Engine_s {
    SDL_Window* window;
    SDL_Renderer* renderer;
} F3D_Engine;

extern int F3D_init(F3D_Engine* engine);
extern int F3D_setDrawColor(F3D_Engine engine, int r, int g, int b, int a);
extern int F3D_clearScene(F3D_Engine engine);
extern void F3D_displayScene(F3D_Engine engine);
extern int F3D_drawLine(F3D_Engine engine, int x1, int y1, int x2, int y2);
extern int F3D_Delay(Uint32 ms);
extern int F3D_doInput(void);
extern void F3D_quit(F3D_Engine engine);
