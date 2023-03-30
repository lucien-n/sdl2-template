#pragma once

#include <SDL2/SDL.h>

#if 0
#include <SDL2/SDL_FontCache.h>
#endif

#include "RenderWindow.hpp"

class Hud
{
public:
    Hud(RenderWindow *window, int fontSize);

    void render(float delta);

private:
    RenderWindow *window;
#if 0
    FC_Font *font;
#endif
};