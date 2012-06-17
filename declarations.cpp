#include "declarations.h"

using namespace std;

// bumper
int x = 190;
int y = 428;
int width = 85;
int height = 20;

// ball
int ballX = 200;
int ballY = 200;
int ballWH = 10;
int ballVelocityX = 2.5;
int ballVelocityY = 2.5;

// keys
bool left = false;
bool right = false;
bool up = false;
bool down = false;

// brick
const int numberofbricks = 20;
Brick bricks[numberofbricks];

char text[255];
// score
bool scoreinit()
{
    int score = 0;
    sprintf(text, "%d", score);

    return true;
}
