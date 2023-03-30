#pragma once

#include <SDL2/SDL.h>

#include "Sprite.hpp"
#include "Camera.hpp"

class RenderWindow
{
public:
    RenderWindow(const char *title, int width, int height, float renderScale);
    float renderScale;
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();

    SDL_Texture *loadTexture(const char *filePath);
    void setCamera(Camera *camera);

    void destroy();
    void clear();
    void render(Sprite &sprite);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Camera *camera;
};