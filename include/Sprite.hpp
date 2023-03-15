#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite
{
public:
    Sprite(float x, float y, SDL_Texture *texture);

    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    SDL_Rect getRect();
    SDL_Texture *getTexture();

private:
    float x, y;
    SDL_Rect rect;
    SDL_Texture *texture;
};