#include <SDL2/SDL.h>

#include "Game.hpp"
#include "RenderWindow.hpp"

int Game::run()
{
    window.setCamera(&camera);

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
        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
            player.event_handler(event.key.keysym.sym, event.type);
    }
}

int Game::update()
{
    player.update();
    camera.update();
}

int Game::draw()
{
    window.clear();

    window.render(grassSprite);

    window.render(player);

    window.display();
}