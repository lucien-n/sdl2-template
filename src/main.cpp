#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Game.hpp"
#include "RenderWindow.hpp"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_Init()", SDL_GetError(), 0);
    if (!IMG_Init(IMG_INIT_PNG))
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "IMG_Init()", SDL_GetError(), 0);
    if (TTF_Init() == -1)
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "TTF_Init()", TTF_GetError(), 0);

    Game game = Game();

    game.run();

    return 0;
}