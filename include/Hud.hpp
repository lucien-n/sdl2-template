#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "RenderWindow.hpp"

class Hud
{
public:
    Hud(RenderWindow *window, int fontSize);

    TTF_Font *getFont();
    void destroy();
    void render(float delta);

private:
    RenderWindow *window;
    TTF_Font *font;
    SDL_Color font_color = {255, 255, 255, 255};
    int font_size = 16;
    std::string font_path = "assets/fonts/reemkufi.ttf";
};