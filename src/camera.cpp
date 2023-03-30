#include <SDL2/SDL.h>

#include "Camera.hpp"
#include "Sprite.hpp"

Camera::Camera(SDL_Window *p_window, Sprite *p_followed, float p_renderScale) : window(p_window), followed(p_followed)
{
    SDL_GetWindowSize(window, windowWidth, windowHeight);
    renderScale = p_renderScale;
}

void Camera::update()
{
    if (followed->getX() - scrollX != 1280 / 2)
        scrollX += followed->getX() * renderScale - (scrollX + 1280 / 2);

    if (followed->getY() - scrollY != 720 / 2)
        scrollY += followed->getY() * renderScale - (scrollY + 720 / 2);
}

void Camera::follow(Sprite *p_followed)
{
    followed = p_followed;
}

float Camera::getScrollX()
{
    return scrollX;
}

float Camera::getScrollY()
{
    return scrollY;
}