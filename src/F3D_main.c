// F3D_main.c : File for library testing

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
        F3D_clearScene(engine);
        F3D_stop = doInput();
        F3D_setDrawColor(engine, 255, 255, 255, 255);
        //F3D_drawGrid(engine);
        F3D_drawTriangle(engine, 100, 100, 200, 200, 300, 300);
        F3D_displayScene(engine);
        F3D_Delay(16);
        printf("Game loop #%d\n", F3D_loop);
        F3D_loop += 1;
    }


    F3D_quit(engine);
    return 0;
}
