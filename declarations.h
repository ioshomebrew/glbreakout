#ifndef DECLARATIONS
#define DECLARATIONS
#include <sdl.h>
#include <sdl_opengl.h>
#include <sdl_ttf.h>

extern bool isRunning;
extern bool left, right;
extern SDL_Event event;

// brick structure
struct Brick
{
    float x;
    float y;
    float width;
    float height;
    bool alive;
};

// bumper
extern int x;
extern int y;
extern int width;
extern int height;

// ball
extern int ballX;
extern int ballY;
extern int ballWH;
extern int ballVelocityX;
extern int ballVelocityY;

// keys
extern bool left;
extern bool right;
extern bool up;
extern bool down;

// brick
extern const int numberofbricks;
extern Brick bricks[];

// score
extern int score;
extern char text[];

#endif
