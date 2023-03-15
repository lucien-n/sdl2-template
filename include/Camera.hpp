#pragma once

#include <SDL2/SDL.h>

#include "Sprite.hpp"

class Camera
{
public:
    Camera(SDL_Window *window, Sprite *followed);

    void update();

    void follow(Sprite *newFollowed);
    float getScrollX();
    float getScrollY();

private:
    int *windowWidth, *windowHeight = 0;
    float scrollX, scrollY = 0.0;
    Sprite *followed;
    SDL_Window *window;
};