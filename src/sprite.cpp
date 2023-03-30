#include <SDL2/SDL.h>

#include "Sprite.hpp"

Sprite::Sprite(float px, float py, SDL_Texture *ptexture) : x(px), y(py), texture(ptexture)
{
    rect.x = 0;
    rect.y = 0;
    int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    rect.w = width;
    rect.h = height;
}

float Sprite::getX()
{
    return x;
}

float Sprite::getY()
{
    return y;
}

void Sprite::setX(float x_)
{
    x = x_;
}

void Sprite::setY(float y_)
{
    y = y_;
}

SDL_Rect Sprite::getRect()
{
    return rect;
}

SDL_Texture *Sprite::getTexture()
{
    return texture;
}
