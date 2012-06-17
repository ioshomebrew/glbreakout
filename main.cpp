#include <sdl.h>
#include <sdl_opengl.h>
#include <iostream>
#include "functions.h"
#include "declarations.h"
#undef main

SDL_Event event;
bool isRunning = true;

int main(int argc, char **argv)
{
    init(argc, argv);

    glDisable(GL_DEPTH_TEST);

    scoreinit();

    for (int i = 0, brickx = 4, bricky = 10; i < numberofbricks; i++, brickx+=66 )
    {
        if( brickx > 600)
        {
            brickx = 4;
            bricky += 30;
        }
        bricks[i].x = brickx;
        bricks[i].y = bricky;
        bricks[i].width = 40;
        bricks[i].height = 20;
        bricks[i].alive = true;
    }

    while(isRunning)
    {
        // events
        while(SDL_PollEvent(&event))
        {
            input();
        }

        logicmain();

        rendermain();

        SDL_Delay(1);
    }

    return 0;
}
