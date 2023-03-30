#include <SDL2/SDL.h>

#include <iostream>

#include "Hud.hpp"
#include "RenderWindow.hpp"

Hud::Hud(RenderWindow *p_window, int p_fontSize)
{
    window = p_window;
}

void Hud::render(float p_delta)
{
    // float fps = 1000 / (p_delta * 1000);
}