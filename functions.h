#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include <gl/glut.h>
#include "declarations.h"
// init
bool init(int argc, char **argv);

// rendering functions
void rendermain();

// input functions
bool input();

// logic functions
bool logickeyboard();
bool logicgame();
bool logicmain();
bool collision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh);

// object functions
bool renderbumper();
bool renderball();
bool renderbricks();

// font functions
bool renderscore();
bool renderlives();

// score functions
bool scoreinit();
