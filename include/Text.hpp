#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class Text
{
public:
    Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color &color);

    SDL_Rect getRect();
    SDL_Texture *getTexture();

    static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color &color);

private:
    SDL_Texture *text_texture = nullptr;
    SDL_Rect text_rect;
};