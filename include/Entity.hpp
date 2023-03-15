#pragma once

#include <SDL2/SDL.h>
#include <tuple>

#include "Sprite.hpp"

class Entity : public Sprite
{
public:
    using Sprite::Sprite;

    void update();

    void move(float x, float y);
};