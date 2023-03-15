#include <SDL2/SDL.h>
#include <tuple>

#include "Entity.hpp"

void Entity::update()
{
}

void Entity::move(float x, float y)
{
    setX(getX() + x);
    setY(getY() + y);
}