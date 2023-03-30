#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <sstream>

#include "Hud.hpp"
#include "RenderWindow.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

Hud::Hud(RenderWindow *p_window, int p_fontSize)
{
    window = p_window;
    font = TTF_OpenFont("assets/fonts/reemkufi.ttf", p_fontSize);
}

TTF_Font *Hud::getFont()
{
    return font;
}

void Hud::destroy()
{
    TTF_CloseFont(font);
}

void Hud::render(float p_delta)
{
    float fpsTextFloat = 1000 / (p_delta * 1000);

    std::ostringstream fpsTextStream;
    fpsTextStream << fpsTextFloat;
    std::string fpsTextString = fpsTextStream.str();

    Text fpsText = Text(window->getRenderer(), font_path, font_size, fpsTextString.c_str(), font_color);

    window->render(fpsText, 4, 4);
}