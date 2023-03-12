#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.hpp"

class RenderWindow
{
public:
    RenderWindow(const char *title, int width, int height, float renderScale);
    float renderScale;
    SDL_Texture *loadTexture(const char *filePath);
    void destroy();
    void clear();
    void render(Sprite &sprite);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};