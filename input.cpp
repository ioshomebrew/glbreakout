#include <sdl_opengl.h>
#include "functions.h"
#include "declarations.h"

bool input()
{
    if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
    {
        isRunning = false;
    }

    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_LEFT)
        {
            left = true;
        }
        else if(event.key.keysym.sym == SDLK_RIGHT)
        {
            right = true;
        }
        else if(event.key.keysym.sym == SDLK_UP)
        {
            up = true;
        }
        else if(event.key.keysym.sym == SDLK_DOWN)
        {
            down = true;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
        if(event.key.keysym.sym == SDLK_LEFT)
        {
            left = false;
        }
        else if(event.key.keysym.sym == SDLK_RIGHT)
        {
            right = false;
        }
        else if(event.key.keysym.sym == SDLK_UP)
        {
            up = false;
        }
        else if(event.key.keysym.sym == SDLK_DOWN)
        {
            down = false;
        }
    }
}

