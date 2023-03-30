#include "Text.hpp"
#include "RenderWindow.hpp"

Text::Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color &color)
{
    text_texture = loadFont(renderer, font_path, font_size, message, color);
    SDL_QueryTexture(text_texture, nullptr, nullptr, &text_rect.w, &text_rect.h);
}

SDL_Rect Text::getRect()
{
    return text_rect;
}

SDL_Texture *Text::getTexture()
{
    return text_texture;
}

SDL_Texture *Text::loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message, const SDL_Color &color)
{
    TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
    if (!font)
        SDL_Log("Failed to load font");

    SDL_Surface *text_surface = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!text_surface)
        SDL_Log("Failed to create text surface");

    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (!text_texture)
        SDL_Log("Failed to create text texture");

    SDL_FreeSurface(text_surface);
    TTF_CloseFont(font);

    return text_texture;
}
