#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "RenderWindow.hpp"
#include "Camera.hpp"
#include "Sprite.hpp"
#include "Player.hpp"
#include "Hud.hpp"

const int WIDTH = 1280;
const int HEIGHT = 720;
const float RENDERSCALE = 2;
const int FONTSIZE = 24;

class Game
{
public:
    RenderWindow window = RenderWindow("SDL2 Template", WIDTH, HEIGHT, RENDERSCALE);

    bool running = true;

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    SDL_Texture *playerTexture = window.loadTexture("assets/textures/player.png");

    Sprite grassSprite = Sprite(50, 50, window.loadTexture("assets/textures/lush_grass.png"));

    Player player = Player(200, 200, playerTexture);

    Camera camera = Camera(window.getWindow(), &player, RENDERSCALE);

    Hud hud = Hud(&window, 24);

    void run();
    void event_handler();
    void update();
    void draw();

private:
    const char *title;
    int width, height;
    float renderScale;
};