#include <SDL2/SDL.h>
#include <tuple>

#include "Entity.hpp"

void Entity::update()
{
}

void Entity::move(float p_x, float p_y)
{
    setX(getX() + p_x);
    setY(getY() + p_y);
}