#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.hpp"
#include "RenderWindow.hpp"

int Game::run()
{
    while (running)
    {
        event_handler();
        update();
        draw();
    }

    window.destroy();
    SDL_Quit();

    return 0;
}

int Game::event_handler()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;
    }
}

int Game::update()
{
    // update
}

int Game::draw()
{
    window.clear();

    // draw

    window.display();
}