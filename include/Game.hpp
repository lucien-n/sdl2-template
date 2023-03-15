#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"
#include "Camera.hpp"
#include "Sprite.hpp"
#include "Player.hpp"

const int WIDTH = 1280;
const int HEIGHT = 720;
const float RENDERSCALE = 2;

class Game
{
public:
    bool running = true;
    RenderWindow window = RenderWindow("SDL2 Template", WIDTH, HEIGHT, RENDERSCALE, NULL);

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    SDL_Texture *playerTexture = window.loadTexture("assets/player.png");

    Sprite grassSprite = Sprite(50, 50, window.loadTexture("assets/lush_grass.png"));

    Player player = Player(200, 200, playerTexture);

    Camera camera = Camera(window.getWindow(), &player, RENDERSCALE);

    int run();
    int event_handler();
    int update();
    int draw();

private:
    const char *title;
    int width, height;
    float renderScale;
};