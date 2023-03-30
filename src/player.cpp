#include <SDL2/SDL.h>

#include "Player.hpp"

void Player::event_handler(SDL_Keycode p_key, Uint32 p_event_type)
{
    bool pressed = p_event_type == SDL_KEYDOWN;
    switch (p_key)
    {
    case SDLK_q:
        setKey(0, pressed);
        break;
    case SDLK_d:
        setKey(1, pressed);
        break;
    case SDLK_z:
        setKey(2, pressed);
        break;
    case SDLK_s:
        setKey(3, pressed);
        break;

    default:
        break;
    }
}

void Player::update(double p_delta)
{
    double deltaSpeed = speed * p_delta;
    if (getKey(0))
        move(-deltaSpeed, 0);
    if (getKey(1))
        move(deltaSpeed, 0);
    if (getKey(2))
        move(0, -deltaSpeed);
    if (getKey(3))
        move(0, deltaSpeed);
}

void Player::setKey(int p_key, bool p_pressed)
{
    keys[p_key] = p_pressed;
}

bool Player::getKey(int p_key)
{
    return keys[p_key];
}

float Player::getSpeed()
{
    return speed;
}

void Player::setSpeed(float p_speed)
{
    speed = p_speed;
}