#include "functions.h"
#include "declarations.h"
#include <sdl.h>
#include <gl/glut.h>

// brick position
int brickx;
int bricky;

bool collision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh)
{
    if(Ay+Ah < By) return false;
    else if(Ay > By+Bh) return false;
    else if(Ax+Aw < Bx) return false;
    else if(Ax > Bx+Bw) return false;

    return true;
}

bool logickeyboard()
{
    // logic
    if(left == true)
    {
        x -= 3;
    }

    if(right == true)
    {
        x += 3;
    }

    return true;
}

bool logicgame()
{
    // bumper logic
    if(x < 0)
    {
        x = 0;
    }

    if(x+width > 640)
    {
        x = 640-width;
    }

    if(y < 0)
    {
        y = 0;
    }

    if(y+height > 480)
    {
        y = 480-height;
    }

    // make ball move
    ballX += ballVelocityX;
    ballY += ballVelocityY;

    for (int i = 0; i < numberofbricks; i++ )
    {
        if(bricks[i].alive == true)
        {
            if(collision(ballX, ballY, ballWH, ballWH, bricks[i].x, bricks[i].y, bricks[i].width, bricks[i].height) == true)
            {
                ballVelocityY = -ballVelocityY;
                bricks[i].alive = false;
                break;
            }
        }
    }

    // ball logic
    if(ballX < 0)
    {
        ballVelocityX = -ballVelocityX;
    }

    else if(ballX+ballWH > 640)
    {
        ballVelocityX = -ballVelocityX;
    }

    if(ballY < 0)
    {
        ballVelocityY = -ballVelocityY;
    }

    else if(ballY+ballWH > 480)
    {
        ballVelocityY = -ballVelocityY;
    }

    if(collision(ballX, ballY, ballWH, ballWH, x, y, width, height) == true)
    {
        ballVelocityY = -ballVelocityY;
    }

    return true;
}

bool logicmain()
{
    logickeyboard();
    logicgame();

    return true;
}

bool renderbumper()
{
    // bumper render loop
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+width, y);
    glVertex2f(x+width, y+height);
    glVertex2f(x, y+height);
    glEnd();

    return true;
}

bool renderball()
{
    // ball rendering
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(ballX, ballY);
    glVertex2f(ballX+ballWH, ballY);
    glVertex2f(ballX+ballWH, ballY+ballWH);
    glVertex2f(ballX, ballY+ballWH);
    glEnd();

    return true;
}

bool renderbricks()
{
    // bricks
    glColor3ub(0, 0, 255);
    glBegin(GL_QUADS);

    for (int i = 0; i < numberofbricks; i++ )
    {
        if(bricks[i].alive == true)
        {
            glVertex2f(bricks[i].x, bricks[i].y);
            glVertex2f(bricks[i].x+bricks[i].width, bricks[i].y);
            glVertex2f(bricks[i].x+bricks[i].width, bricks[i].y+bricks[i].height);
            glVertex2f(bricks[i].x, bricks[i].y+bricks[i].height);
        }
    }

    glEnd();

    return true;
}

bool renderscore()
{

    return true;
}

void rendermain()
{
    // rendering
    glClear(GL_COLOR_BUFFER_BIT);

    // rendering loop
    glPushMatrix();

    glOrtho(0, 640, 480, 0, -1, 1); // set matrix

    renderbumper();

    renderball();

    renderbricks();

    renderscore();

    glPopMatrix();

    SDL_GL_SwapBuffers();
}
