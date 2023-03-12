#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"

const int WIDTH = 800;
const int HEIGHT = 600;
const float RENDERSCALE = 2;

class Game
{
public:
    bool running = true;

    RenderWindow window = RenderWindow("SDL2 Template", WIDTH, HEIGHT, RENDERSCALE);

    int run();
    int event_handler();
    int update();
    int draw();

private:
    const char *title;
    int width, height;
    float renderScale;
};