#include <SDL2/SDL.h>

#include <iostream>

#include "Camera.hpp"
#include "Sprite.hpp"

Camera::Camera(SDL_Window *window, Sprite *followed, float renderScale_) : window(window), followed(followed)
{
    SDL_GetWindowSize(window, windowWidth, windowHeight);
    renderScale = renderScale_;
}

void Camera::update()
{
    if (followed->getX() - scrollX != 1280 / 2)
        scrollX += followed->getX() * renderScale - (scrollX + 1280 / 2);

    if (followed->getY() - scrollY != 720 / 2)
        scrollY += followed->getY() * renderScale - (scrollY + 720 / 2);
}

void Camera::follow(Sprite *newFollowed)
{
    followed = newFollowed;
}

float Camera::getScrollX()
{
    return scrollX;
}

float Camera::getScrollY()
{
    return scrollY;
}