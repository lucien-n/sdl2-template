#include <SDL2/SDL.h>

#include <time.h>

#include "Game.hpp"
#include "RenderWindow.hpp"

void Game::run()
{
    window.setCamera(&camera);
    player.setSpeed(300);

    while (running)
    {
        event_handler();
        update();
        draw();
    }

    window.destroy();
    SDL_Quit();
}

void Game::event_handler()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;
        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
            player.event_handler(event.key.keysym.sym, event.type);
    }
}

void Game::update()
{
    // update delta time
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();
    deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

    // update game components
    player.update(deltaTime);
    camera.update();
}

void Game::draw()
{
    window.clear();

    window.render(grassSprite);

    window.render(player);

    hud.render(deltaTime);

    window.display();
}