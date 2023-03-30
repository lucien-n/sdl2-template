#pragma once

#include <SDL2/SDL.h>

#include "Sprite.hpp"

class Camera
{
public:
    Camera(SDL_Window *window, Sprite *followed, float renderScale);
    float renderScale;

    void update();

    void follow(Sprite *newFollowed);
    float getScrollX();
    float getScrollY();

private:
    int *windowWidth, *windowHeight;
    float scrollX, scrollY;
    SDL_Window *window;
    Sprite *followed;
};