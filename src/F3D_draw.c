// F3D_draw : Implementation of draw functions

#include "F3D_api.h"

void F3D_drawGrid(F3D_Engine engine) {
    // Draw grid
    for (int i = 0; i < WINDOW_WIDTH; i += 10) {
        F3D_drawLine(engine, i, 0, i, WINDOW_HEIGHT);
    }
    for (int i = 0; i < WINDOW_HEIGHT; i += 10) {
        F3D_drawLine(engine, 0, i, WINDOW_WIDTH, i);
    }
}

void F3D_drawTriangle(F3D_Engine engine, int x1, int y1, int x2, int y2, int x3, int y3) {
    F3D_drawLine(engine, x1, y1, x2, y2);
    F3D_drawLine(engine, x2, y2, x3, y3);
    F3D_drawLine(engine, x3, y3, x1, y1);
}

